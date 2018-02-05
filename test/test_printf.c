#include "../ft_printf.h"

// int		ft_printf(const char *string, ...)
// {
// 	va_list 		ap;
// 	long int				s;
// 	//t_printf		*params;
// 	//t_printf		*list;

// 	//params = (t_printf *)malloc(sizeof(t_printf));
// 	//ft_find_params(string, params);
// 	va_start(ap, string);
// 	s = va_arg(ap, int);
// 	printf("%8.15hhd\n", -12345);
// 	//printf("%s\n", ft_itoa_base(14, 8, 0));
// 	// s = va_arg(ap, char*);
// 	// printf("%s\n", s);
// 	// s = va_arg(ap, char*);
// 	// printf("%s\n", s);
// 	va_end(ap);
// 	//ft_free(params);
// 	return (0);
// }

int		main(void)
{
	int lol;

	lol = -13;
	printf("% 2i", lol);
	//ft_printf("%28.15hi", lol);
}