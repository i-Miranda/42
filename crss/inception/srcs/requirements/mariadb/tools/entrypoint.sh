#!/bin/sh
set -eu

DATADIR=/var/lib/mysql
SOCKET=/run/mysqld/mysqld.sock
MARKER="$DATADIR/.inception_initialized"

: "${MYSQL_DATABASE:?MYSQL_DATABASE is required}"
: "${MYSQL_USER:?MYSQL_USER is required}"

DB_PASSWORD=$(cat /run/secrets/db_password)
DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

# Limit values interpolated into SQL to safe characters.
is_hex() {
    case "$1" in
        ''|*[!0123456789abcdefABCDEF]*) return 1 ;;
        *) return 0 ;;
    esac
}

case "$MYSQL_DATABASE" in
    *[!a-zA-Z0-9_]*|'')
        echo "Error: MYSQL_DATABASE must contain only letters, digits, and underscores" >&2
        exit 1
        ;;
esac

case "$MYSQL_USER" in
    *[!a-zA-Z0-9_]*|'')
        echo "Error: MYSQL_USER must contain only letters, digits, and underscores" >&2
        exit 1
        ;;
esac

if ! is_hex "$DB_PASSWORD" || ! is_hex "$DB_ROOT_PASSWORD"; then
    echo "Error: database passwords must contain only hexadecimal characters" >&2
    exit 1
fi

mkdir -p /run/mysqld "$DATADIR"
chown mysql:mysql /run/mysqld
chown -R mysql:mysql "$DATADIR"
rm -f "$SOCKET"

if [ -f "$MARKER" ]; then
    echo "MariaDB already initialized; starting normally."
    exec mariadbd --user=mysql --datadir="$DATADIR"
fi

# Do not try passwordless setup against an existing, unmarked database.
if [ -d "$DATADIR/mysql" ]; then
    echo "Error: system tables already exist, but initialization marker is missing." >&2
    echo "Refusing to initialize over an existing database." >&2
    exit 1
fi

echo "Initializing fresh MariaDB datadir..."
mariadb-install-db \
    --user=mysql \
    --datadir="$DATADIR" \
    --auth-root-authentication-method=normal

mariadbd \
    --user=mysql \
    --datadir="$DATADIR" \
    --socket="$SOCKET" \
    --skip-networking &
TEMP_PID=$!

cleanup() {
    kill "$TEMP_PID" 2>/dev/null || true
    wait "$TEMP_PID" 2>/dev/null || true
}
trap cleanup EXIT INT TERM

i=0
until mariadb-admin --no-defaults --socket="$SOCKET" -u root ping >/dev/null 2>&1; do
    i=$((i + 1))
    if [ "$i" -ge 30 ]; then
        echo "Error: temporary MariaDB server did not become ready" >&2
        exit 1
    fi
    sleep 1
done

mariadb --no-defaults --socket="$SOCKET" -u root <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
CREATE DATABASE \`${MYSQL_DATABASE}\`;
CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

# Only mark successful setup. If setup fails, the next start will stop safely
# rather than treating a partially initialized datadir as a fresh one.
touch "$MARKER"
chown mysql:mysql "$MARKER"

kill "$TEMP_PID"
wait "$TEMP_PID" 2>/dev/null || true
trap - EXIT INT TERM

exec mariadbd --user=mysql --datadir="$DATADIR"
