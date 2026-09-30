# Use Debian Bookworm as the base image
FROM	debian:bookworm

# Install MariaDB and clean up the package lists
RUN		apt-get update && \
		apt-get install -y mariadb-server && \
		rm -rf /var/lib/apt/lists/*

# Replace the default MariaDB configuration
COPY	conf/mariadb.cnf /etc/mysql/mariadb.conf.d/99-inception.cnf

# /run/mysqld is the directory MariaDB uses for runtime files such as:
	# mysqld.sock - the UNIX socket file
	# mysqld.pid - the process ID file
# chown -R to recursively change ownership, allowing MariaDB to create its
	# socket and PID files in /run/mysqld and read and write the database files
		# in /var/lib/mysql
	# owner : mysql
	# group : mysql
RUN		mkdir -p /run/mysqld && \
		chown -R mysql:mysql /run/mysqld /var/lib/mysql

# Documents MariaDB's default listening port
	# EXPOSE does NOT publish the port to the host.
	# Publishing must be done with:
		# docker run -p 3306:3306 <container-name>
EXPOSE	3306

# Run MariaDB with user mysql and keeps the logs attached to the container's
	# STDOUT & STDERR. This makes them visible with:
		# docker logs <container-name>
CMD		["mariadbd", "--user=mysql", "--console"]
