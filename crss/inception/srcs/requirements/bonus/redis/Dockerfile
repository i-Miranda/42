# Use Debian Bookworm as the base image
FROM	debian:bookworm

RUN		apt-get update && \
		apt-get install -y redis && \
		rm -rf /var/lib/apt/lists/*

COPY conf/redis.conf /etc/redis.conf

EXPOSE 6379

STOPSIGNAL SIGTERM

CMD ["redis-server", "/etc/redis.conf"]
