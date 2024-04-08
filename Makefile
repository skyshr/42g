# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 17:37:11 by ksuh              #+#    #+#              #
#    Updated: 2024/04/07 15:09:43 by ksuh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_BASIC = ft_bzero.c ft_isdigit.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c a_four1.c \
		a_four2.c a_four3.c a_four4.c a_four5.c a_four6.c a_handle_data.c \
		a_order_four1.c a_order_four2.c a_order_three.c a_three.c b_four1.c \
		b_four2.c b_four3.c b_four4.c b_four5.c b_four6.c b_handle_data.c \
		b_order_four1.c b_order_four2.c b_order_three.c b_three.c \
		check_validation.c operation1.c operation2.c parse_data.c main.c

SRCS_BONUS = ft_strncmp.c ft_isdigit.c ft_isalpha.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c \
		check_validation.c operation1.c operation2.c parse_data.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c \
		error.c

OBJS_BASIC = $(SRCS_BASIC:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME_BASIC = push_swap
NAME_BONUS = checker

ifndef bonus
OBJS = $(OBJS_BASIC)
NAME = $(NAME_BASIC)
else
OBJS = $(OBJS_BONUS)
NAME = $(NAME_BONUS)
endif

all : $(NAME) 

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c 
	$(CC) $(CFLAGS) -c $^

clean :	
	rm -rf $(OBJS_BASIC) 
	rm -rf $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME_BASIC)
	rm -rf $(NAME_BONUS)
	
re : fclean all

bonus :
	make bonus=1 all

.PHONY : all clean fclean re bonus
