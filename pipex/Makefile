# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 11:27:46 by ksuh              #+#    #+#              #
#    Updated: 2024/05/08 21:34:57 by ksuh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

SRCS_BASIC = error.c pipex.c utils.c split.c

SRCS_BONUS = error_bonus.c pipex_bonus.c utils_bonus.c \
			utils2_bonus.c split_bonus.c

OBJS_BASIC = $(SRCS_BASIC:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = pipex

LIBDIR = ./libft
LIB = libft.a

all : LAST_ALL

bonus : LAST_BONUS

$(LIB) :
	make -C $(LIBDIR)
	cp $(LIBDIR)/$(LIB) $(LIB)

clean :	
	make clean -C $(LIBDIR)
	rm -f $(OBJS_BASIC) 
	rm -f $(OBJS_BONUS)

fclean :
	make fclean -C $(LIBDIR)
	rm -f $(OBJS_BASIC) 
	rm -f $(OBJS_BONUS)
	rm -f $(LIB)
	rm -f $(NAME)
	rm -f LAST_ALL
	rm -f LAST_BONUS

re : fclean all

.PHONY : all clean fclean re bonus

LAST_ALL : $(OBJS_BASIC) $(LIB)
	rm -f LAST_BONUS
	$(CC) $(CFLAGS) -o $(NAME) $^
	touch $@

LAST_BONUS : $(OBJS_BONUS) $(LIB)
	rm -f LAST_ALL
	$(CC) $(CFLAGS) -o $(NAME) $^
	touch $@
