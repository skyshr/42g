#!/bin/bash

service vsftpd start

adduser $FTP_USER --disabled-password

echo "$FTP_USER:$FTP_PWD" | /usr/sbin/chpasswd

echo "$FTP_USER" | tee -a /etc/vsftpd.userlist

mkdir -p /home/$FTP_USER/ftp/files

chown nobody:nogroup /home/$FTP_USER/ftp
chmod a-w /home/$FTP_USER/ftp

chown $FTP_USER:$FTP_USER /home/$FTP_USER/ftp/files

service vsftpd stop

exec "$@"