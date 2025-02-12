# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 13:07:52 by ksuh              #+#    #+#              #
#    Updated: 2024/06/22 13:10:23 by ksuh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRCS = action.c error.c init.c main.c monitor.c print.c utils.c

OBJS= $(SRCS:.c=.o)

NAME = philo

all : $(NAME) 

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $^

clean :	
	rm -rf $(OBJS)

fclean : 
	rm -rf $(OBJS)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

