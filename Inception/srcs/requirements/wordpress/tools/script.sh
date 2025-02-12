#!/bin/bash

mkdir -p /var/www/html
rm -rf /var/www/html/*
cd /var/www/html

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

wp core download --allow-root
mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
cp /wp-config.php /var/www/html/wp-config.php

sed -i -r "s/mysql_database/$MYSQL_DATABASE/1" wp-config.php
sed -i -r "s/mysql_user/$MYSQL_USER/1" wp-config.php
sed -i -r "s/mysql_password/$MYSQL_PASSWORD/1" wp-config.php

wp core install --url=$DOMAIN_NAME/ --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root

wp user create $WP_USER $WP_EMAIL --role=author --user_pass=$WP_PWD --allow-root

wp theme install astra --activate --allow-root

wp plugin install redis-cache --activate --allow-root
wp redis enable --allow-root

wp plugin update --all --allow-root

mkdir -p /run/php

exec "$@"
