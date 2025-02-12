DC = docker-compose
DIR = srcs
ENV = .env
NAME = docker-compose.yml
DATADIR = /home/ksuh/data

.PHONY: all up down build clean fclean re

all: up

up: build
	mkdir -p $(DATADIR)/wordpress
	mkdir -p $(DATADIR)/mariadb

	$(DC) -f $(DIR)/$(NAME) --env-file $(DIR)/$(ENV) up -d

down:
	$(DC) -f $(DIR)/$(NAME) down

build:
	$(DC) -f $(DIR)/$(NAME) --env-file $(DIR)/$(ENV) build

clean:
	$(DC) -f $(DIR)/$(NAME) down --rmi all --volumes --remove-orphans

fclean: clean
	rm -rf $(DATADIR)

re: fclean build up