FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install dumb-init wget php php-mysql -y

COPY ./requirements/bonus/adminer/tools/script.sh /

RUN chmod +x script.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--", "/script.sh"]
# ENTRYPOINT ["/script.sh"]
# dumpinit tini
