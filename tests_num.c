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
#include <limits.h>
#include <signal.h>
#include <string.h>

int main(void)
{
	//int ret;

	//wchar_t lool[] = L"пріветікі";
	setlocale(LC_ALL, "");
	ft_printf("|% 0+.0llo|", 0);
	//ft_printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	// ft_printf("{%-15p}\n", 0);
	// ft_printf("{%.p}\n", 0);
	// ft_printf("{%.0p}\n", 0);
	// ft_printf("{%.5p}\n", 0);
	// ft_printf("{%12.0p}\n", 0);
	// ft_printf("{%12.3p}\n", 0);
	// ft_printf("{%12.12p}\n", 0);
	// ft_printf("{%12.3p}\n", 0);
	// ft_printf("{%-10p}", &strlen);
	//ft_printf("%i\n" ,ft_printf("{%-15Z}", 123));
	//ft_printf("{%-15Z}", 123);
		// test->debug = 1;
	//ft_printf("%i", ft_printf("{%-15Z}", 123));
	//ft_printf("\n");
	//ft_printf("%5.2p", 5);
	//ft_printf("\n");
	// printf("%.0p, %.p", 0, 0);
	// printf("%i", printf("%C", lool[0]));
	// printf("%i", printf("%C", lool[1]));
	// printf("%i", printf("%C", lool[2]));
	// printf("%i", printf("%C", lool[3]));
	// printf("%i", printf("%C", lool[4]));
	// printf("%i", printf("%C", lool[5]));
	// printf("%i", printf("%C", lool[6]));
	// printf("%i", printf("%C", lool[7]));
	// printf("%i", printf("%C", lool[8]));
	// printf("%i", printf("%C", lool[9]));
	// printf("%i", printf("%C", lool[10]));
	// ft_printf("%li\n", 12);
	// ft_printf("\n%li\n", 12);
	// ft_printf("\n%li\n", 12);
	// ft_printf("\n%li\n", 12);
	// ft_printf("\n%li\n", 12);
	// ft_printf("\n%li\n", 12);
	// ft_printf("\n%li\n", 12);
	// ft_printf("%i", ft_printf("%c", lool[0]));
	// ft_printf("\n");
	// printf("%i\n", printf("%c", lool[0]));
	// lol = ft_printf("ivuhviuhivue%i  2fihfo2  %ioeuhefoifeoi", 13, 14);
	// ret = ft_printf("%05%");
	// ft_printf("\n");
	//ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	//ft_printf("%");
	//ft_printf("\n");
	// ft_printf("num: %i", ft_printf("%X", 0));
	//printf("%i\n", ret);
	//printf("%028C", lool[0]);
	//ft_printf(" my: %i", ft_printf("ivuhviuhivue%i  2fihfo2  %ioeuhefoifeoi", 13, 14));
	// ft_printf("\n");
	// printf(" or: %i", printf("ivuhviuhivue%i  2fihfo2  %ioeuhefoifeoi", 13, 14));
	// ft_printf("%i\n", ft_printf("%C\n", lool[0]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[1]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[2]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[3]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[4]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[5]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[6]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[7]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[8]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[9]));
	// ft_printf("%i\n", ft_printf("%C\n", lool[10]));
	// ft_printf("\n");
	//printf("%i\n", ft_printf("%S\n", lool));
	//system("leaks ft_printf");
  // setlocale(LC_ALL, "RUS");
  // printf("Привет мир! \n");
  // return 0;
// printf("@moulitest: %#.o %#.0o\n", 0, 0);
// printf("@moulitest: %#.x %#.0x\n", 0, 0);
// printf("@moulitest: %#.X %#.0X\n", 0, 0);
// ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
// ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
// ft_printf("@moulitest: %#.X %#.0X\n", 0, 0);
// printf("@moulitest: %.o %.0o\n", 0, 0);
// printf("@moulitest: %.x %.0x\n", 0, 0);
// printf("@moulitest: %.X %.0X\n", 0, 0);
// ft_printf("@moulitest: %.o %.0o\n", 0, 0);
// ft_printf("@moulitest: %.x %.0x\n", 0, 0);
// ft_printf("@moulitest: %.X %.0X\n", 0, 0);
// ft_printf("%");
// ft_printf("% ");
// ft_printf("% h");
// ft_printf("%Z");
// ft_printf("test\n");
// ft_printf("% hZ");
// ft_printf("%05%");              
// ft_printf("%-05%");                     
// ft_printf("% hZ%");                
// ft_printf("% Z", "test");          
// ft_printf("% Z ", "test");     
// ft_printf("% Z%s", "test");         
// ft_printf("%000   %", "test");          
// ft_printf("%%%", "test");            
// ft_printf("%%   %", "test");           
// ft_printf("%ll#x", 9223372036854775807);
// ft_printf("%010s is a string", "this");  
// ft_printf("%-010s is a string", "this"); 
// ft_printf("%05c", 42);            
// ft_printf("% Z", 42);
// ft_printf("%0 d", 42);         
// ft_printf("%0 d", -42);     
// ft_printf("% 0d", 42); 
// ft_printf("% 0d", -42);      
// ft_printf("%5+d", 42);     
// ft_printf("%5+d", -42);           
// ft_printf("%-5+d", 42);              
// ft_printf("%-0+5d", 42);   
// ft_printf("%-5+d", -42);  
// ft_printf("%-0+5d", -42);
// ft_printf("%zhd", 4294967296); 
// ft_printf("%jzd", 9223372036854775807); 
// ft_printf("%jhd", 9223372036854775807); 
// ft_printf("%lhl", 9223372036854775807); 
// ft_printf("%lhlz", 9223372036854775807);
// ft_printf("%zj", 9223372036854775807);
// ft_printf("%lhh", 2147483647);
// ft_printf("%hhld", 128); 
// ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256); 
// ft_printf("@main_ftprintf: %####0000 33..1d", 256);
//  ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
//system("leaks ft_printf");                   
}