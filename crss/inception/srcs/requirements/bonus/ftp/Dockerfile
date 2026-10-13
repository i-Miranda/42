# Use Debian Bookworm as the base image
FROM	debian:bookworm

RUN		apt-get update && \
		apt-get install -y vsftpd shadow && \
		rm -rf /var/lib/apt/lists/*

RUN 	mkdir -p /var/run/vsftpd/empty &&\
		mkdir -p /var/www/html

COPY 	conf/vsftpd.conf /etc/vsftpd/vsftpd.conf

EXPOSE 	21 40000-40010

STOPSIGNAL SIGTERM

CMD ["redis-server", "/etc/redis.conf"]
