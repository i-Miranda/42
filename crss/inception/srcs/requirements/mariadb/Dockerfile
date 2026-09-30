# Use Debian Bookworm as the base image
FROM	debian:bookworm

# Install MariaDB and clean up the package lists
RUN		apt-get update && \
		apt-get install -y mariadb-server && \
		rm -rf /var/lib/apt/lists/*

COPY	conf/mariadb.cnf /etc/mysql/mariadb.conf.d/99-inception.cnf

RUN		mkdir -p /run/mysqld && \
		chown -R mysql:mysql /run/mysqld /var/lib/mysql

CMD		["mariadbd", "--user=mysql", "--console"]
