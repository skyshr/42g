# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 20:56:56 by jajo              #+#    #+#              #
#    Updated: 2024/06/28 16:40:18 by ksuh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT = libft/libft.a

BUILTINS = builtins_dir.c builtins_env_utils.c builtins_env.c builtins.c

UTILS = asterisk.c aster_pattern.c aster_readdir.c env_oper_utils.c error.c order_str.c order_str_utils.c parenthesis_validation.c validation.c

PARSER = ft_parser.c ft_parser_init.c ft_parser_utils.c ft_parser_tree.c ft_parser_make_token.c ft_parser_make_node.c ft_parser_lexer_utils.c

ETC = handle_operations.c init_minishell.c main.c

PIPE = pipe_execute_utils.c pipe_execute.c pipe_heredoc.c pipe_interpret_utils.c pipe_interpret.c pipe_tree.c pipe.c pipe_utils.c pipe_utils2.c

SIGNAL = signal_do.c signal_set.c

SPLIT = split_pipe_utils1.c split_pipe_utils2.c split_pipe_utils3.c split_pipe.c split_utils.c 

SRCS = $(BUILTINS) $(UTILS) $(PARSER) $(ETC) $(PIPE) $(SIGNAL) $(SPLIT)

OBJS = ${SRCS:.c=.o}

NAME = minishell

all : ${NAME}

${NAME} : ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} -o $@ $^ ${LIBFT} -lreadline

${LIBFT}:
	make -C ./libft
.c.o :
	${CC} ${CFLAGS} -c -o $@ $<
	
clean :
	rm -rf ${OBJS}
	make -C ./libft clean

fclean :
	make clean
	rm -rf ${NAME}
	make -C ./libft fclean

re :
	make -C ./libft re
	make fclean
	make

.PHONY: all clean fclaen re
