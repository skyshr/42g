# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 17:37:11 by ksuh              #+#    #+#              #
#    Updated: 2024/03/15 12:56:33 by ksuh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_BASIC = ft_checkformat.c ft_isvalidformat.c ft_itoa_address.c ft_itoa_hex.c \
		ft_itoa_int.c ft_itoa_uint.c ft_print_address.c ft_print_char.c \
		ft_print_hex.c ft_print_int.c ft_print_percent.c ft_print_str.c \
		ft_print_uint.c ft_printf.c setbase.c

SRCS_BONUS = ft_checkformat_bonus.c ft_isvalidformat_bonus.c ft_itoa_address_bonus.c \
		ft_itoa_hex_bonus.c ft_itoa_int_bonus.c ft_itoa_uint_bonus.c ft_print_address_bonus.c \
		ft_print_char_bonus.c ft_print_hex_bonus.c ft_print_int_bonus.c ft_print_percent_bonus.c \
		ft_print_str_bonus.c ft_print_uint_bonus.c ft_printf_bonus.c setbase_bonus.c \
		ft_checkflag_bonus.c ft_checklength_bonus.c ft_checkprecision_bonus.c \
		ft_checkwidth_bonus.c ft_printc_bonus.c ft_printh_bonus.c ft_printi_bonus.c \
		ft_printp_bonus.c ft_prints_bonus.c ft_printu_bonus.c ft_setprint_bonus.c \
		ft_setstate_bonus.c handle_length_bonus.c print_inti_nneg_bonus.c print_inti_npos_bonus.c \
		print_inti_yneg_bonus.c print_inti_ypos_bonus.c print_nhex_bonus.c print_yhex_bonus.c \
		setaddr_bonus.c setchar_bonus.c sethex_bonus.c setint_bonus.c setstr_bonus.c setuint_bonus.c

OBJS_BASIC = $(SRCS_BASIC:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
LIBDIR = srcs
LIB = $(LIBDIR)/libft.a

ifndef BONUS
	OBJS = $(OBJS_BASIC)
else
	OBJS = $(OBJS_BONUS)
endif

NAME = libftprintf.a

all : $(NAME) 

$(NAME) : $(OBJS)
	$(MAKE) -C $(dir $(LIB))
	cp $(LIB) ./$(NAME)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :	
	rm -rf $(OBJS_BASIC) $(OBJS_BONUS)
	$(MAKE) -C $(dir $(LIB)) clean

fclean :
	rm -rf $(OBJS_BASIC) $(OBJS_BONUS) $(NAME)
	$(MAKE) -C $(dir $(LIB)) fclean

re : fclean all

bonus : 	
	make BONUS=1 all

.PHONY : all clean fclean re bonus
