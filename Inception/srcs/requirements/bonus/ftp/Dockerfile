FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y && apt-get install vsftpd -y

COPY ./requirements/bonus/ftp/conf/vsftpd.conf /etc/
COPY ./requirements/bonus/ftp/tools/script.sh /

RUN chmod +x script.sh

ENTRYPOINT ["/script.sh"]

CMD ["/usr/sbin/vsftpd"]
