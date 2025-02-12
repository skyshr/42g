#!/bin/bash

service mariadb start

sleep 2

echo "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE ;" > inception.sql
echo "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD' ;" >> inception.sql
echo "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' ;" >> inception.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD' ;" >> inception.sql
echo "FLUSH PRIVILEGES;" >> inception.sql

mysql < inception.sql
kill $(cat /var/run/mysqld/mysqld.pid)

exec "$@"