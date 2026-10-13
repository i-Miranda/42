# Use Debian Bookworm as the base image
FROM	debian:bookworm

# Install PHP-FPM, WordPress PHP extensions, MariaDB client, and utilities
RUN		apt-get update && \
		apt-get install -y \
		php-fpm \
		php-cli \
		php-mysql \
		php-curl \
		php-mbstring \
		php-xml \
		php-zip \
		php-gd \
		mariadb-client \
		curl \
		ca-certificates && \
		rm -rf /var/lib/apt/lists/*

RUN curl -fSL https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    -o /usr/local/bin/wp \
    && chmod +x /usr/local/bin/wp \
    && wp --info

# Replace the default PHP-FPM configuration
COPY	conf/www.conf	/etc/php/8.2/fpm/pool.d/www.conf

RUN		mkdir -p /run/php

COPY tools/entrypoint.sh /usr/local/bin/wordpress-entrypoint
RUN chmod +x /usr/local/bin/wordpress-entrypoint

# Documents PHP-FPM's default listening port
	# EXPOSE does NOT publish the port to the host.
	# Publishing must be done with:
		# docker run -p 9000:9000 <container-name>
EXPOSE	9000

STOPSIGNAL SIGTERM

# Run PHP-FPM in the foreground
CMD		["/usr/local/bin/wordpress-entrypoint"]
