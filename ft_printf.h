#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *string, ...);
char	ft_find_params(const char *string);

#endif