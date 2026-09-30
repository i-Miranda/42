# Use Debian Bookworm as the base image
FROM	debian:bookworm

# Install Nginx and OpenSSL and clean up the package lists
RUN		apt-get update && \
		apt-get install -y nginx openssl && \
		rm -rf /var/lib/apt/lists/*

# Generate a self-signed TLS certificate and private key
	# -x509 tells OpenSSL to generate a self-signed X.509 certificate instead
		# of generating a CSR (Certificate-Signing Request)
	# -nodes tells OpenSSL to not encrypt the private key with a password
	# -newkey rsa:2048 generates a new 2048-bit RSA private key
	# -days 30 the certificate will be valid for 30 days. It does not renew
		# automatically. To create a new certificate, you must either rebuild
			# the image or generate a replacement certificate at runtime.
	# -subj supplies the certificate subject non-interactively. Without them,
		# OpenSSL would ask you to enter these values interactively during the
			# image build
		# C - country: ES
		# ST - state or region: Madrid
		# L - locality or city: Madrid
		# O - organization: 42
		# OU - organizational unit: 42Madrid
		# CN - common name: ivmirand.42.fr
	# -addext adds a SAN (Subject Alternative Name). Modern browsers prefer SAN
		# over relying only on the certificate's CN.
RUN		mkdir -p /etc/nginx/ssl && \
		openssl req -x509 -nodes -newkey rsa:2048 \
		-out /etc/nginx/ssl/nginx.crt \
		-keyout /etc/nginx/ssl/nginx.key \
		-days 30 \
		-subj "/C=ES/ST=Madrid/L=Madrid/O=42/OU=42Madrid/CN=ivmirand.42.fr" \
		-addext "subjectAltName=DNS:ivmirand.42.fr"

# Replace the default Nginx configuration
COPY	conf/nginx.conf /etc/nginx/nginx.conf

# Run Nginx in the foreground
CMD		["nginx", "-g", "daemon off;"]
