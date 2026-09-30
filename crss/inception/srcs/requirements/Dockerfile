# Use Debian Bookworm as the base image
FROM	debian:bookworm

# Install Nginx and clean up the package lists
RUN		apt-get update && \
		apt-get install -y nginx && \
		rm -rf /var/lib/apt/lists/*

# Replace the default Nginx configuration
COPY	conf/nginx.conf /etc/nginx/nginx.conf

# Run Nginx in the foreground
CMD		["nginx", "-g", "daemon off;"]
