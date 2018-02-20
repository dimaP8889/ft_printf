#include "ft_printf.h"

static void	ft_add_out_num_sharp_p(t_printf *params)
{
	if (!params->precision && params->check_zero)
	{
		params->out_num[0] = '0';
		params->out_num = ft_addletter(params->out_num, 'x');
	}
	else
	{
		params->out_num[0] = '0';
		params->out_num[1] = 'x';
	}
}

static void	ft_add_out_num(t_printf *params, t_flags_num *flag)
{
	if (params->check_num == -1)
		params->out_num[0] = '-';
	else if (flag->plus == 1)
		params->out_num[0] = '+';
	else if (flag->space == 1)
		params->out_num[0] = ' ';
	else if (flag->sharp_o == 1)
		params->out_num[0] = '0';
	else if (flag->sharp_x == 1)
	{
		params->out_num[0] = '0';
		params->out_num[1] = 'x';
	}
	else if (flag->sharp_p == 1)
		ft_add_out_num_sharp_p(params);
	else if (flag->sharp_X == 1)
	{
		params->out_num[0] = '0';
		params->out_num[1] = 'X';
	}
}

static void	ft_add_out_sharp_p(t_printf *params, int count)
{
	if (!params->precision && params->check_zero)
	{
		params->out[count + 1] = '0';
		params->out_num[0] = 'x';
	}
	else
	{
		params->out[count] = '0';
		params->out[count + 1] = 'x';
	}
}

static void	ft_add_out(t_printf *params, int x, t_flags_num *flag)
{
	int count;

	count = 0;
	while (params->out[count + x])
		count++;
	if (params->check_num == -1)
		params->out[count] = '-';
	else if (flag->plus == 1)
		params->out[count] = '+';
	else if (flag->space == 1)
		params->out[count] = ' ';
	else if (flag->sharp_o == 1)
		params->out[count] = '0';
	else if (flag->sharp_x == 1)
	{
		params->out[count] = '0';
		params->out[count + 1] = 'x';
	}
	else if (flag->sharp_p == 1)
		ft_add_out_sharp_p(params, count);
	else if (flag->sharp_X == 1)
	{
		params->out[count] = '0';
		params->out[count + 1] = 'X';
	}
}

void	ft_finish_flags(t_printf *params, t_flags_num *flag)
{
	int		x;

	x = 1;
	if (params->width <= params->precision 
		|| params->width <= (int)ft_strlen(params->string))
		ft_add_letter(params, flag);
	else if (params->width > params->precision)
	{
		if (flag->sharp_x == 1 || flag->sharp_X == 1 || flag->sharp_p == 1)
			x = 2;
		if (flag->zero == 0)
			ft_add_out(params, x, flag);
		else
			ft_add_out_num(params, flag);
	}
}