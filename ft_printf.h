#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

# define CONVERS "sSpdDioOuUxXcC%\0"
# define FLAGS "#0-+ \0"
# define SIZES "hljz\0"

typedef struct			s_printf
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
	char				*out;
	char				*out_num;
	int 				flag_minus;
	int 				flag_sharp;
	struct	s_printf	*next;
}						t_printf;

typedef struct			s_size
{
	char				hh;
	unsigned char		u_hh;
	short				h;
	unsigned short		u_h;
	int					i;
	unsigned int		u_i;
	long				l;
	unsigned long		u_l;
	long long			ll;
	unsigned long long	u_ll;
	intmax_t			j;
	uintmax_t			u_j;
	size_t				z;
}						t_size;

int		ft_printf(const char *string, ...);
void	ft_find_params(const char *string, t_printf *params);
void	ft_converse(t_printf *params, void *string);
char	*ft_strjoin_free(char **s1, char const *s2);
char	*ft_itoa_base(size_t index, int base, int hex);

#endif