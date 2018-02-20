#include "ft_printf.h"

static void	ft_add_letter_sharp_p(t_printf *params)
{
	if (!params->precision && params->check_zero)
	{
		params->out_num[0] = '0';
		params->out_num = ft_addletter(params->out_num, 'x');
	}
	else
	{
		params->out = ft_addletter(params->out, '0');
		params->out = ft_addletter(params->out, 'x');
	}
}

void	ft_add_letter(t_printf *params, t_flags_num *flag)
{
	if (params->check_num == -1)
		params->out = ft_addletter(params->out, '-');
	else if (flag->plus == 1)
		params->out = ft_addletter(params->out, '+');
	else if (flag->space == 1)
		params->out = ft_addletter(params->out, ' ');
	else if (flag->sharp_o == 1)
		params->out = ft_addletter(params->out, '0');
	else if (flag->sharp_x == 1)
	{
		params->out = ft_addletter(params->out, '0');
		params->out = ft_addletter(params->out, 'x');
	}
	else if (flag->sharp_p == 1)
		ft_add_letter_sharp_p(params);
	else if (flag->sharp_X == 1)
	{
		params->out = ft_addletter(params->out, '0');
		params->out = ft_addletter(params->out, 'X');
	}
}
