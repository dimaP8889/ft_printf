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
	int					flag_minus;
	int					flag_zero;
	int					base;
	char				*string;
	int					check_num;
	int					return_val;
	int					check_zero;
	int					flag_space;
	int					flag_plus;
	int					flag_sharp_o;
	int					flag_sharp_x;
	int					flag_sharp_X;
	int					flag_mv;
	int					move;
	struct	s_printf	*next;
}						t_printf;

typedef struct			s_flags_num
{
	int					count_zer;
	int					count_sharp;
	int					count_plus;
	int					count_x;
	char				*plus;
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

#endif