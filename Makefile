# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:dpogrebn <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 11:01:38 by dpogrebn          #+#    #+#              #
#    Updated: 2017/12/16 16:25:35 by dpogrebn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_L = ft_printf
CC = gcc
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
MAIN = tests_num.c
SRC = ft_printf.c ft_find_params.c ft_converse.c ft_itoa_base.c ft_converse_numb.c \
ft_make_flag.c ft_print_num.c ft_sizes_l_z.c ft_make_unicode_char.c ft_pars.c ft_pars_extra_f.c \
ft_converse_extra_f.c ft_sizes_h_hh.c ft_make_flag_minus.c ft_make_flag_minus_adl.c \
ft_finish_flags.c ft_set_flags.c
OBJ = ft_printf.o ft_find_params.o ft_converse.o ft_itoa_base.o ft_converse_numb.o \
ft_make_flag.o ft_print_num.o ft_sizes_l_z.o ft_make_unicode_char.o ft_pars.o ft_pars_extra_f.o \
ft_converse_extra_f.o ft_sizes_h_hh.o ft_make_flag_minus.o ft_make_flag_minus_adl.o \
ft_finish_flags.o ft_set_flags.o
HEADER = ft_printf.h

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	cd libft && make re && cp libft.a ../ && cd .. && mv libft.a $(NAME)
	ar -q $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

re: fclean all
