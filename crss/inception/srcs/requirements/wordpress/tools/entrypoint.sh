#!/bin/sh
set -eu

WP_PATH=/var/www/html

: "${WP_DB_NAME:?Set WP_DB_NAME in .env}"
: "${WP_DB_USER:?Set WP_DB_USER in .env}"
: "${WP_DB_PASSWORD_FILE:?Set WP_DB_PASSWORD_FILE in .env}"
: "${WP_ADMIN_USER:?Set WP_ADMIN_USER in .env}"
: "${WP_ADMIN_PASSWORD_FILE:?Set WP_ADMIN_PASSWORD_FILE in .env}"
: "${WP_ADMIN_EMAIL:?Set WP_ADMIN_EMAIL in .env}"
: "${WP_USER:?Set WP_USER in .env}"
: "${WP_USER_PASSWORD_FILE:?Set WP_USER_PASSWORD_FILE in .env}"
: "${WP_USER_EMAIL:?Set WP_USER_EMAIL in .env}"

WP_DB_HOST=${WP_DB_HOST:-mariadb}
WP_URL=${WP_URL:-https://127.0.0.1:8443}

[ -r "$WP_DB_PASSWORD_FILE" ] || {
    echo "Cannot read DB password file: $WP_DB_PASSWORD_FILE" >&2
    exit 1
}
[ -r "$WP_ADMIN_PASSWORD_FILE" ] || {
    echo "Cannot read WordPress admin password file: $WP_ADMIN_PASSWORD_FILE" >&2
    exit 1
}
[ -r "$WP_USER_PASSWORD_FILE" ] || {
    echo "Cannot read WordPress user password file: $WP_USER_PASSWORD_FILE" >&2
    exit 1
}

DB_PASSWORD=$(cat "$WP_DB_PASSWORD_FILE")
ADMIN_PASSWORD=$(cat "$WP_ADMIN_PASSWORD_FILE")
USER_PASSWORD=$(cat "$WP_USER_PASSWORD_FILE")

if [ ! -f "$WP_PATH/wp-includes/version.php" ]; then
    curl -fsSL https://wordpress.org/latest.tar.gz -o /tmp/wordpress.tar.gz
    tar -xzf /tmp/wordpress.tar.gz -C /tmp
    cp -a /tmp/wordpress/. "$WP_PATH/"
    rm -rf /tmp/wordpress /tmp/wordpress.tar.gz
fi

cd "$WP_PATH"

if [ ! -f wp-config.php ]; then
    wp config create \
        --allow-root \
        --path="$WP_PATH" \
        --dbname="$WP_DB_NAME" \
        --dbuser="$WP_DB_USER" \
        --dbpass="$DB_PASSWORD" \
        --dbhost="$WP_DB_HOST" \
		--skip-check
fi

# Set or update the URL constants, including the forwarded port.
wp config set WP_HOME "$WP_URL" \
    --type=constant --allow-root --path="$WP_PATH"
wp config set WP_SITEURL "$WP_URL" \
    --type=constant --allow-root --path="$WP_PATH"

# Wait up to 60 seconds for MariaDB to accept connections.
attempt=0
until wp db check --allow-root --path="$WP_PATH" >/dev/null 2>&1; do
    attempt=$((attempt + 1))
    if [ "$attempt" -ge 30 ]; then
        echo "MariaDB did not become ready or WordPress cannot connect to it." >&2
        exit 1
    fi
    sleep 2
done

# Install only if this persistent WordPress database isn't installed yet.
if ! wp core is-installed --allow-root --path="$WP_PATH"; then
    wp core install \
        --allow-root \
        --path="$WP_PATH" \
        --url="$WP_URL" \
        --title="Inception" \
        --admin_user="$WP_ADMIN_USER" \
        --admin_password="$ADMIN_PASSWORD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --skip-email
fi

if ! wp user get "$WP_USER" --field=ID --allow-root --path="$WP_PATH" >/dev/null 2>&1; then
    wp user create "$WP_USER" "$WP_USER_EMAIL" \
        --role=author \
        --user_pass="$USER_PASSWORD" \
        --allow-root \
        --path="$WP_PATH"
fi

chown -R www-data:www-data "$WP_PATH"
exec php-fpm8.2 -F
