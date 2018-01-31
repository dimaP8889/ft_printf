#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

# define CONVERS "sSpdDioOuUxXcC%\0"
# define FLAGS "#0-+ \0"
# define SIZES "hljz\0"

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
	int					found_perc;
	struct	s_printf	*next;
}				t_printf;

int		ft_printf(const char *string, ...);
void	ft_find_params(const char *string, t_printf *params);

#endif