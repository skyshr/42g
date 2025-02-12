# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 17:37:11 by ksuh              #+#    #+#              #
#    Updated: 2024/06/28 18:33:40 by jajo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRCS = ft_split.c ft_strchr.c ft_memcpy.c ft_memmove.c \
		ft_strjoin.c ft_strlcpy.c ft_strlen.c \
		ft_substr.c ft_strncmp.c ft_strcmp.c ft_putchar_fd.c \
		get_next_line.c ft_putstr_fd.c ft_putendl_fd.c ft_atoi.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdel_node.c ft_lstfind_node.c ft_lstlast.c \
		ft_lstnew.c ft_lstsize.c ft_isspace.c ft_itoa.c \
		ft_isquote.c ft_isdigit.c ft_isalpha.c ft_isalnum.c \
		ft_ispipe.c ft_isoper_or.c ft_issign.c ft_isoperand.c \
		ft_isredirection.c ft_memset.c ft_isparenthesis.c ft_strdup.c
		
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
