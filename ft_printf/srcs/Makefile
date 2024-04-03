# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 17:37:11 by ksuh              #+#    #+#              #
#    Updated: 2024/03/13 11:27:10 by ksuh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_bzero.c ft_calloc.c ft_max.c ft_memset.c ft_min.c \
		ft_putchar.c ft_putstr.c ft_strdup.c ft_strlcpy.c ft_strlen.c

OBJS = $(SRCS:.c=.o)
NAME = libft.a
INCDIR = ../includes

all : $(NAME) 

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -I$(INCDIR)

clean :	
	rm -rf $(OBJS) 

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
