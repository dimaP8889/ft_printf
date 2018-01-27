#include "ft_printf.h"

char	ft_find_params(const char *string)
{
	while (*string != '%' && *string)
	{
		ft_putchar(*string);
		string++;
	}
	
	return(0);
}