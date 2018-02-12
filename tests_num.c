/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 18:39:22 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/05 18:39:24 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>
#include <stdio.h>

int main(void)
{
	wint_t	lol = 65;

	setlocale(LC_ALL, "");
	printf("%lc\n", lol);
	ft_printf("%lc", lol);
	ft_printf("\n");
    return 0;
}