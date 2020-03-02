# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 18:24:23 by acarlett          #+#    #+#              #
#    Updated: 2020/03/02 18:30:23 by acarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FOR_CHECK =  first_main.c  \
libft/ft_putstr.c \
libft/ft_atoi.c \
second_main.c \
push.c \
swap.c \
rotate.c \
reverse_rotate.c \
libft/ft_isalpha.c

FOR_PUSH = push_swap.c \
libft/ft_atoi.c \
libft/ft_putstr.c \
libft/ft_isalpha.c \
rotate.c \
swap.c \
reverse_rotate.c \
push.c \
make_A_take_MinMidMax.c \

all:
	@gcc -o checker $(FOR_CHECK) -I lib_push.h

fclean:
	@rm -rf checker
	@rm -rf push_swap

main: all
	./checker

ps:
	@gcc -o push_swap $(FOR_PUSH) -I lib_push.h
