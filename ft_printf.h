#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
#include <stdio.h>

# define CONVERS "sSpdDioOuUxXcC%\0"
# define FLAGS "#0-+ \0"
# define SIZES "hljz\0"

typedef struct			s_printf
{
	char				*pars;
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
	int					base;
	char				*string;
	int					check_num;
	int					return_val;
	int					check_zero;
	int					move;
	int 				tihs;
	struct	s_printf	*next;
}						t_printf;

typedef struct			s_flags_num
{
	int					sharp_X;
	int					sharp_x;
	int					sharp_o;
	int					count_x;
	int					plus;
	int 				space;
	int 				zero;
	int 				minus;
	char				*sharp;
}						t_flags_num;

typedef struct			s_size
{
	signed char			hh;
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
	size_t				u_z;
	ssize_t				z;
}						t_size;

int		ft_printf(const char *string, ...);
int		ft_find_params(const char *string, t_printf *params);
void	ft_converse(t_printf *params, void *string);
char	*ft_strjoin_free(char **s1, char const *s2);
char	*ft_itoa_base(size_t index, int base, int hex);
void	ft_make_flag(t_printf *params);
void	ft_check_size_l(t_printf *params, t_size *size, void *number);
void	ft_check_size_h(t_printf *params, t_size *size, void *number);
void	ft_check_size_hh(t_printf *params, t_size *size, void *number);
void	ft_check_size_ll(t_printf *params, t_size *size, void *number);
void	ft_check_size_j(t_printf *params, t_size *size, void *number);
void	ft_check_size_z(t_printf *params, t_size *size, void *number);
void	ft_make_out(t_printf *params);
void	ft_check_no_size(t_printf *params, t_size *size, void *number);
void	ft_check_size(t_printf *params, t_size *size, void *number);
void	ft_print_num(t_printf *params, t_size **size);
void	ft_make_unicode_char(unsigned int symb);

#endif