FROM debian:bullseye

RUN apt update && \
    apt upgrade -y && \
    apt install -y mariadb-server

EXPOSE 3306

COPY ./requirements/mariadb/conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./requirements/mariadb/tools/script.sh /

RUN chmod 644 /etc/mysql/mariadb.conf.d/
RUN chmod +x script.sh

ENTRYPOINT ["/script.sh"]

CMD ["mysqld", "--console"]
