# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 17:37:11 by ksuh              #+#    #+#              #
#    Updated: 2024/05/08 18:57:15 by ksuh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_split.c ft_strchr.c ft_memcpy.c ft_memmove.c \
		ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c \
		ft_substr.c ft_strncmp.c ft_strcmp.c ft_putchar_fd.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c \
		ft_putstr_fd.c ft_putendl_fd.c
		
OBJS = $(SRCS:.c=.o)

NAME = libft.a

all : $(NAME) 

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o : %.c 
	$(CC) $(CFLAGS) -c $^ -o $@

clean :	
	rm -rf $(OBJS) 

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
