FROM debian:bullseye

RUN apt update && apt upgrade -y
RUN apt install php-mysql \
    php-fpm \
    php7.4 \
    php php-cli \
    php-curl \
    php-gd \
    php-mbstring \
    php-xml \
    php-zip \
    php-opcache \
    php-redis \
    curl -y

EXPOSE 9000

COPY ./requirements/wordpress/conf/www.conf /etc/php/7.4/fpm/pool.d/
COPY ./requirements/wordpress/tools/script.sh /
COPY ./requirements/wordpress/tools/wp-config.php /

RUN chmod +x /script.sh

ENTRYPOINT [ "/script.sh" ]
CMD ["/usr/sbin/php-fpm7.4", "-F"]
