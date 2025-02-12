# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 13:07:52 by ksuh              #+#    #+#              #
#    Updated: 2024/06/18 13:45:03 by ksuh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BASIC_DIR = philo
BONUS_DIR = philo_bonus

ifndef BONUS
DIR=$(BASIC_DIR)
else
DIR=$(BONUS_DIR)
endif

all :
	make -C $(DIR)

clean :	
	make clean -C $(BASIC_DIR)
	make clean -C $(BONUS_DIR)

fclean : 
	make fclean -C $(BASIC_DIR)
	make fclean -C $(BONUS_DIR)

re : fclean all

bonus :
	make BONUS=1 all

.PHONY : all clean fclean re

