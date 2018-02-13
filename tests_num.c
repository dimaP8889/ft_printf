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
	wchar_t lool[] = L"тобі пізда";
	setlocale(LC_ALL, "");
	// printf("%i\n", printf("%C\n", lool[0]));
	// printf("%i\n", printf("%C\n", lool[1]));
	// printf("%i\n", printf("%C\n", lool[2]));
	// printf("%i\n", printf("%C\n", lool[3]));
	// printf("%i\n", printf("%C\n", lool[4]));
	// printf("%i\n", printf("%C\n", lool[5]));
	// printf("%i\n", printf("%C\n", lool[6]));
	// printf("%i\n", printf("%C\n", lool[7]));
	// printf("%i\n", printf("%C\n", lool[8]));
	// printf("%i\n", printf("%C\n", lool[9]));
	// printf("%i\n", printf("%C\n", lool[10]));
	//ft_printf("%i\n", );
	// ft_printf("%li\n", 12);
	// ft_printf("\n%li\n", 12);
	// ft_printf("\n%li\n", 12);
	// ft_printf("\n%li\n", 12);
	// ft_printf("\n%li\n", 12);
	// ft_printf("\n%li\n", 12);
	// ft_printf("\n%li\n", 12);
	ft_printf("%i\n", ft_printf("%C\n", lool[1]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[2]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[3]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[4]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[5]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[6]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[7]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[8]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[9]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[10]));
	//printf("%i\n", ft_printf("%S\n", lool));
	system("leaks ft_printf");
	//ft_printf("\n");
	return 0;
  // setlocale(LC_ALL, "RUS");
  // printf("Привет мир! \n");
  // return 0;
}