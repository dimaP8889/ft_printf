/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_unicode_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:32:30 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/12 16:32:31 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_make_two_bits(unsigned int symb)
{
	unsigned int num1;
	unsigned int num2;

	num1 = num2 = symb;
	num1 = num1 & 63;
	num1 = num1 | 128;
	num2 = num2 >> 6;
	num2 = num2 & 31;
	num2 = num2 | 192;
	ft_putchar(num2);
	ft_putchar(num1);
}

void	ft_make_three_bits(unsigned int symb)
{
	unsigned int num1;
	unsigned int num2;
	unsigned int num3;

	num1 = num2 = num3 = symb;
	num1 = num1 >> 12;
	num1 = num1 | 224;
	num2 = num2 >> 6;
	num2 = num2 & 63;
	num2 = num2 | 128;
	num3 = num3 & 63;
	num3 = num3 | 128;
	ft_putchar(num1);
	ft_putchar(num2);
	ft_putchar(num3);	
}

void	ft_make_four_bits(unsigned int symb)
{
	unsigned int num1;
	unsigned int num2;
	unsigned int num3;
	unsigned int num4;

	num1 = num2 = num3 = num4 = symb;
	num1 = num1 >> 18;
	num1 = num1 | 240;
	num2 = num2 >> 12;
	num2 = num2 & 63;
	num2 = num2 | 128;
	num3 = num3 >> 6;
	num3 = num3 & 63;
	num3 = num3 | 128;
	num4 = num4 & 63;
	num4 = num4 | 128;
	ft_putchar(num1);
	ft_putchar(num2);
	ft_putchar(num3);
	ft_putchar(num4);	
}

void	ft_make_unicode_char(unsigned int symb)
{
	if (symb < 128)
		ft_putchar(symb);
	else if (symb < 2048)
		ft_make_two_bits(symb);
	else if (symb < 65536)
		ft_make_three_bits(symb);
	else if (symb < 1114112)
		ft_make_four_bits(symb);
}