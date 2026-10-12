#!/bin/sh
set -e

# Read secrets
DB_PASSWORD=$(cat /run/secrets/db_password)
DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

if [ -z "$MYSQL_DATABASE" ] || [ -z "$MYSQL_USER" ]; then
    echo "Error: MYSQL_DATABASE or MYSQL_USER not defined"
    exit 1
fi

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld /var/lib/mysql

# Initialize only once using your marker file
if [ -f "/var/lib/mysql/.inception_initialized" ]; then
    echo ">>> SKIPPING INITIALIZATION: Already initialized! <<<"
else
    echo ">>> RUNNING MARIAADB INITIALIZATION <<<"

    # Bootstrap mode lets us run initial setup commands securely offline
    mariadbd --user=mysql --datadir=/var/lib/mysql --bootstrap <<EOF
FLUSH PRIVILEGES;

CREATE USER IF NOT EXISTS 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';

CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;

CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';

FLUSH PRIVILEGES;
EOF

    touch /var/lib/mysql/.inception_initialized
    echo ">>> INITIALIZATION FINISHED <<<"
fi

# Hand over to the main production server
exec mariadbd --user=mysql --datadir=/var/lib/mysql
