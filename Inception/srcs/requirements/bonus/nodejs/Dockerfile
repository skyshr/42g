FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y && apt-get install nodejs npm -y

COPY ./requirements/bonus/nodejs/tools /home/app

WORKDIR /home/app

RUN npm init -y && npm install express -y

CMD ["node", "server.js"]