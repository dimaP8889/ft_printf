#include "ft_printf.h"

void	ft_set_flags(t_flags_num *flag)
{
	flag->sharp_X = 0;
	flag->sharp_x = 0;
	flag->sharp_o = 0;
	flag->sharp_p = 0;
	flag->count_x = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->minus = 0;
}
