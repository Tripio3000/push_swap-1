# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 18:24:23 by acarlett          #+#    #+#              #
#    Updated: 2020/08/07 18:53:00 by acarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

SOURCES =		sources/push.c \
				sources/rotate.c \
				sources/reverse_rotate.c \
				sources/second_main.c \
				sources/swap.c \
				sources/helper.c \
				sources/second_helper.c \
				sources/last_helper.c \
				sources/make_last.c \
				sources/mini.c \
				sources/another_mini.c \
				sources/new.c \

SOURCES_LIB = 	libft/ft_atoi.c \
				libft/ft_isalpha.c \
				libft/ft_putstr.c \

PUSH_SWAP = sources/take_minmidmax.c \
			sources/make_second.c \

CHECKER =	sources/first_main.c \

INCLUDES = includes/lib_push.h \

INCLUDES_LIB = includes/libft.h \

OBJECTS = $(patsubst %.c,%.o,$(SOURCES)$(PUSH_SWAP)$(CHECKER)$(SOURCES_LIB))

NAME_P = push_swap

NAME_C = checker

all: $(NAME_P) $(NAME_C)


$(NAME_P): $(OBJECTS)
	@make -C libft re
	@cc -g $(FLAGS) -o $(NAME_P) $(PUSH_SWAP) $(SOURCES) -I $(INCLUDES) libft/libft.a
	@rm -rf push_swap.dSYM

$(NAME_C): $(OBJECTS)
	@cc -g $(FLAGS) -o $(NAME_C) $(SOURCES) $(CHECKER) -I $(INCLUDES) libft/libft.a
	@rm -rf checker.dSYM

%.o: %.c $(INCLUDES) $(INCLUDES_LIB)
	@cc $(FLAGS) -I $(INCLUDES) $< -c -o $@ -g

clean:
	@rm -rf push_swap.dSYM
	@rm -rf checker.dSYM
	@rm -rf $(OBJECTS)
	@make -C libft clean

fclean: clean
	@rm -rf checker
	@rm -rf push_swap
	@make -C libft fclean

re: fclean all

main: all
	./checker

make a: all ps

ps:
	@gcc -g -o push_swap $(FOR_PUSH) -I lib_push.h
