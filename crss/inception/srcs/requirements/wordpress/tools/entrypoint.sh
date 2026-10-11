#!/bin/sh
set -e

if [ ! -f /var/www/html/wp-includes/version.php ]; then
    curl -fsSL https://wordpress.org/latest.tar.gz -o /tmp/wordpress.tar.gz
    tar -xzf /tmp/wordpress.tar.gz -C /tmp
    cp -a /tmp/wordpress/. /var/www/html/
    rm -rf /tmp/wordpress /tmp/wordpress.tar.gz
fi

CONFIG=/var/www/html/wp-config.php
if [ ! -f "$CONFIG" ]; then
    CONFIG=/var/www/html/wp-config-sample.php
fi

if [ -f "$CONFIG" ] && ! grep -q "define('WP_HOME'" "$CONFIG"; then
    sed -i "/That's all, stop editing!/i\\
define('WP_HOME', 'https://127.0.0.1:8443');\\
define('WP_SITEURL', 'https://127.0.0.1:8443');\\
" "$CONFIG"
fi

chown -R www-data:www-data /var/www/html
exec php-fpm8.2 -F
