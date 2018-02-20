#include "ft_printf.h"

static void	ft_swap_letters_x_p(t_printf *params)
{
	char 	x;
	char 	o;
	int		count;

	count = 0;
	while (params->out[count])
			count++;
	x = params->out[count - 1];
	o = params->out[count - 2];
	count--;
	while (count >= 2)
	{
		params->out[count] = params->out[count - 2];
		count--;
	}
	params->out[0] = o;
	params->out[1] = x;
}

static void	ft_swap_letters_else(t_printf *params)
{
	char 	x;
	int		count;

	count = 0;
	while (params->out[count])
		count++;
	x = params->out[count - 1];
	count--;
	while (count >= 1)
	{
		params->out[count] = params->out[count - 1];
		count--;
	}
	params->out[0] = x;
}

static void	ft_swap_letters(t_printf *params, t_flags_num *flag)
{
	if (flag->sharp_x == 1 || flag->sharp_X == 1 || flag->sharp_p == 1)
		ft_swap_letters_x_p(params);
	else if (flag->sharp_o == 1 || flag->space == 1 ||
	flag->plus == 1 || params->check_num == -1)
		ft_swap_letters_else(params);
}

static void	ft_flag_minus_move_str(t_printf *params, t_flags_num *flag)
{
	if (params->check_num == -1)
	{
		params->out_num++;
		params->move++;
	}
	else if (flag->plus == 1)
	{
		params->out_num++;
		params->move++;
	}
	else if (flag->space == 1)
	{
		params->out_num++;
		params->move++;
	}
	else if (flag->sharp_o == 1)
	{
		params->out_num++;
		params->move++;
	}
	else if (flag->sharp_x == 1 || flag->sharp_X == 1 || flag->sharp_p)
	{
		params->out_num = params->out_num + 2;
		params->move = params->move + 2;
	}
}

void	ft_flag_minus(t_printf *params, t_flags_num *flag)
{
	char *str;

	str = params->out;
	params->out = params->out_num;
	params->out_num = str;
	ft_add_letter(params, flag);
	ft_swap_letters(params, flag);
	if (ft_strlen(params->out_num) != 0)
		ft_flag_minus_move_str(params, flag);
}