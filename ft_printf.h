#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

# define CONVERS "sSpdDioOuUxXcC\0"
# define FLAGS "#0-+ \0"
# define SIZES "hljz\0"

int		ft_printf(const char *string, ...);
char	ft_find_params(const char *string);

typedef struct	s_printf
{
	char 				*pars;
	int					width;
	char				*width_char;
	int					precision;
	char				*precision_char;
	char				*flag;
	char				*size;
	char				*convers;
	char				*print;
	struct	s_printf	*next;
}				t_printf;

#endif