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

# Replace the default PHP-FPM configuration
COPY	copy/www.conf	/etc/php/8.2/fpm/pool.d/www.conf

RUN		mkdir -p /run/php

# Documents PHP-FPM's default listening port
	# EXPOSE does NOT publish the port to the host.
	# Publishing must be done with:
		# docker run -p 9000:9000 <container-name>
EXPOSE	9000

# Run PHP-FPM in the foreground
CMD		["php-fpm8.2", "-F"]
