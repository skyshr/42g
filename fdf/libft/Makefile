# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 17:37:11 by ksuh              #+#    #+#              #
#    Updated: 2024/03/02 17:11:45 by ksuh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_max.c ft_min.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c \
		ft_substr.c ft_tolower.c ft_atoi_base.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c
		
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
