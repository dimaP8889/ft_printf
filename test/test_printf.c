#include "../ft_printf.h"

int		ft_printf(const char *string, ...)
{
	va_list 		ap;
	void			*s;
	//t_printf		*params;
	//t_printf		*list;

	//params = (t_printf *)malloc(sizeof(t_printf));
	//ft_find_params(string, params);
	va_start(ap, string);
	s = va_arg(ap, void*);
	printf("%i\n", (int)s);
	// s = va_arg(ap, char*);
	// printf("%s\n", s);
	// s = va_arg(ap, char*);
	// printf("%s\n", s);
	va_end(ap);
	//ft_free(params);
	return (0);
}

int		main(void)
{
	ft_printf("HELLO+-39%-+%sciucbwbui457", 13 , "ajajak");
}