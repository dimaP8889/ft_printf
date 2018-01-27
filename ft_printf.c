#include "ft_printf.h"

int		ft_printf(const char *string, ...)
{
	va_list ap;
	char	*s;

	ft_find_params(string);
	va_start(ap, string);
	printf("%s\n", string);
	s = va_arg(ap, char*);
	printf("%s\n", s);
	s = va_arg(ap, char*);
	printf("%s\n", s);
	va_end(ap);
	return (0);
}

int		main(void)
{
	ft_printf("HELLO%s", "lol", "ajajak");
}