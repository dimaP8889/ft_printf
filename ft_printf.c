#include "ft_printf.h"

int		ft_printf(const char *string, ...)
{
	va_list ap;
	char	*s;

	ft_find_params(string);
	va_start(ap, string);
	s = va_arg(ap, char*);
	// printf("%s\n", string);
	// while (s)
	// {
	// 	printf("%s\n", s);
	// 	s = va_arg(ap, char*);
	// }
	va_end(ap);
	// printf("%s\n", s);
	// s = va_arg(ap, char*);
	// printf("%s\n", s);
	// va_end(ap);
	return (0);
}

int		main(void)
{
	ft_printf("HELLO%+-394.898hhsciucbwbui%hhs", "lol", "ajajak");
}