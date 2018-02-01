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

NAME = ft_printf
CC = gcc
NAME_L = printflibft.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_find_params.c ft_converse.c ft_itoa_base.c

all: $(NAME)

$(NAME):
	cd libft && make re && cp libft.a ../ && cd .. && mv libft.a $(NAME_L)

comp:
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(NAME_L)