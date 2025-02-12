#!/bin/bash

if [ ! -f /etc/ssl/certs/nginx.crt ] || [ ! -f /etc/ssl/private/nginx.key ]; then
echo "Nginx: setting up ssl ...";
openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt -subj "/C=KR/ST=gyeongsanbuk-do/L=gyeongsan/O=wordpress/CN=localhost";
echo "Nginx: ssl is set up!"
fi

exec "$@"