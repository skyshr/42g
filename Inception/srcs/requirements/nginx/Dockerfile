FROM debian:bullseye

RUN apt update && apt upgrade -y && apt-get install nginx openssl -y

EXPOSE 443

COPY ./requirements/nginx/conf/default /etc/nginx/sites-enabled/default
COPY ./requirements/nginx/tools/script.sh /

RUN chmod +x script.sh

ENTRYPOINT ["/script.sh"]

CMD ["nginx", "-g", "daemon off;"]
