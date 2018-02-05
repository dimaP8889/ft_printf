#include "ft_printf.h"

void	ft_flag_zero(t_printf *params, t_flags_num *flag)
{
	if (!ft_strcmp(params->precision_char, ""))
	{
		while(params->out[flag->count_zer] == ' ')
		{
			if (params->check_num == -1)
			{
				params->out[0] = '-';
				flag->count_zer++;
				params->check_num = 1;
			}
			params->out[flag->count_zer] = '0';
			flag->count_zer++;
		}
	}
}

void	ft_flag_plus(t_printf *params, t_flags_num *flag)
{
	if (params->check_num == 1)
	{
		if (ft_strcmp(params->out, ""))
		{
			while (params->out[flag->count_plus + 1])
				flag->count_plus++;
			params->out[flag->count_plus] = '+';
		}
		else
		{
			flag->plus = params->out_num;
			params->out_num = ft_strjoin("+", flag->plus);
			free(flag->plus);
		}
	}
}

void	ft_flag_sharp(t_printf *params, t_flags_num *flag, char *string)
{
	if (!ft_strcmp(params->convers, "o"))
	{
		if (((int)ft_strlen(string) >= params->precision))
		{
			if (ft_strcmp(params->out, ""))
			{
				while (params->out[flag->count_sharp + 1])
					flag->count_sharp++;
				params->out[flag->count_sharp] = '0';
			}
			else
			{
				flag->sharp = params->out_num;
				params->out_num = ft_strjoin("0", flag->sharp);
				free(flag->sharp);
			}
		}
	}
	else if (!ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "p"))
	{
		while (params->out[flag->count_x])
			flag->count_x++;
		if (flag->count_x < 1)
		{
			flag->sharp = params->out_num;
			params->out_num = ft_strjoin("0x", flag->sharp);
			free(flag->sharp);
		}
		else
		{
			while (params->out[flag->count_sharp + 2])
				flag->count_sharp++;
			params->out[flag->count_sharp] = '0';
			params->out[flag->count_sharp + 1] = 'x';
		}
	}
	else if (!ft_strcmp(params->convers, "X"))
	{
		while (params->out[flag->count_x])
			flag->count_x++;
		if (flag->count_x < 1)
		{
			flag->sharp = params->out_num;
			params->out_num = ft_strjoin("0X", flag->sharp);
			free(flag->sharp);
		}
		else
		{
			while (params->out[flag->count_sharp + 2])
				flag->count_sharp++;
			params->out[flag->count_sharp] = '0';
			params->out[flag->count_sharp + 1] = 'X';
		}
	}
}

void	ft_set_flags(t_flags_num *flag)
{
	flag->count_zer = 0;
	flag->count_sharp = 0;
	flag->count_plus = 0;
	flag->count_x = 0;
}

void	ft_make_flag(t_printf *params, char *string)
{
	t_flags_num *flag;
	int			count;

	count = 0;
	flag = (t_flags_num *)malloc(sizeof(t_flags_num));
	while (params->flag[count])
	{
		ft_set_flags(flag);
		if (params->flag[count] == '0')
			ft_flag_zero(params, flag);
		else if (params->flag[count] == ' ')
		{
			if (params->check_num > 0 
			&& ((int)ft_strlen(string) >= params->width))
				params->out = ft_addletter(params->out, ' ');
		}
		else if (params->flag[count] == '+')
			ft_flag_plus(params, flag);
		else if (params->flag[count] == '-')
			params->flag_minus = 1;
		else if (params->flag[count] == '#')
			ft_flag_sharp(params, flag, string);
		count++;
	}
	free(flag);
}
void	ft_make_out(char *string, t_printf *params)
{
	int			count_perc;
	int 		length;

	count_perc = params->precision;
	if (params->width > params->precision 
	&& params->precision > (int)ft_strlen(string))
		length = params->width - params->precision;
	if (params->width > params->precision 
	&& params->precision <= (int)ft_strlen(string))
		length = params->width - (int)ft_strlen(string);
	if (params->width <= params->precision)
		length = 0;
	length = length - (params->check_num == 1 ? 0 : 1);
	if (ft_strcmp(params->width_char, ""))
		while (length-- > 0)
			params->out = ft_addletter(params->out, ' ');
	if (ft_strcmp(params->precision_char, ""))
		while (count_perc > (int)ft_strlen(string))
		{
			params->out_num = ft_addletter(params->out_num, '0');
			count_perc--;
		}
	ft_make_flag(params, string);
	if (params->check_num == -1)
		params->out_num = ft_addletter(params->out_num, '-');
}

int		ft_find_base(t_printf *params)
{
	if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "O"))
		return (8);
	else if (!ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X")
	|| !ft_strcmp(params->convers, "p"))
		return (16);
	else
		return (10);
}

void	ft_check_size_l(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->convers, "d") 
		|| !ft_strcmp(params->convers, "i") || !ft_strcmp(params->convers, "D"))
	{
		size->l = (long)number;
		if (size->l < 0)
		{
			params->check_num = -1;
			size->l = -size->l;
		}
			params->string = ft_itoa_base((size_t)size->l, params->base, 0);
	}
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "O")
		|| !ft_strcmp(params->convers, "u") || !ft_strcmp(params->convers, "U")
		|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_l = (unsigned long)number;
		params->string = ft_itoa_base((size_t)size->u_l, 
			params->base, (params->convers[0] == 'X' ? 1 : 0));
	}
}

void	ft_check_size_hh(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
	{
		size->hh = (char)number;
		if (size->hh < 0)
		{
			params->check_num = -1;
			size->hh = -size->hh;
		}
		params->string = ft_itoa_base((size_t)size->hh, params->base, 0);
	}
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
		|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_hh = (unsigned char)number;
		if (size->u_hh < 0)
		{
			params->check_num = -1;
			size->u_hh = -size->u_hh;
		}
		params->string = ft_itoa_base((size_t)size->u_hh, 
		params->base, (params->convers[0] == 'X' ? 1 : 0));
	}
}

void	ft_check_size_h(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
	{
		size->h = (char)number;
		if (size->h < 0)
		{
			params->check_num = -1;
			size->h = -size->h;
		}
		params->string = ft_itoa_base((size_t)size->h, params->base, 0);
	}
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
		|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_h = (unsigned char)number;
		if (size->u_h < 0)
		{
			params->check_num = -1;
			size->u_h = -size->u_h;
		}
		params->string = ft_itoa_base((size_t)size->u_h, 
		params->base, (params->convers[0] == 'X' ? 1 : 0));
	}
}

void	ft_check_size_ll(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
	{
		size->ll = (long long)number;
		if (size->ll < 0)
		{
			params->check_num = -1;
			size->ll = -size->ll;
		}
		params->string = ft_itoa_base((size_t)size->ll, params->base, 0);
	}
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
		|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_ll = (unsigned long long)number;
		params->string = ft_itoa_base((size_t)size->u_ll, 
		params->base, (params->convers[0] == 'X' ? 1 : 0));
	}
}

void	ft_check_size_j(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
	{
		size->j = (intmax_t)number;
		if (size->j < 0)
		{
			params->check_num = -1;
			size->j = -size->j;
		}
		params->string = ft_itoa_base((size_t)size->j, params->base, 0);
	}
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
		|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_j = (uintmax_t)number;
		params->string = ft_itoa_base((size_t)size->u_j, 
		params->base, (params->convers[0] == 'X' ? 1 : 0));
	}
}

void	ft_check_size(t_printf *params, t_size *size, void *number)
{	
	if (!ft_strcmp(params->size, "l") || !ft_strcmp(params->convers, "D") 
		|| !ft_strcmp(params->convers, "U") || !ft_strcmp(params->convers, "O"))
		ft_check_size_l(params, size, number);
	else if (!ft_strcmp(params->size, "hh"))
		ft_check_size_hh(params, size, number);
	else if (!ft_strcmp(params->size, "h"))
		ft_check_size_l(params, size, number);
	else if (!ft_strcmp(params->size, "ll"))
		ft_check_size_ll(params, size, number);
	else if (!ft_strcmp(params->size, "j"))
		ft_check_size_j(params, size, number);
	else if (!ft_strcmp(params->size, "z"))
	{
		if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i") 
			|| !ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
			|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
		{
			size->z = (size_t)number;
			params->string = ft_itoa_base((size_t)size->z, 
			params->base, (params->convers[0] == 'X' ? 1 : 0));
		}
	}
}

void	ft_print_num(t_printf *params, t_size **size)
{
	if (params->flag_minus == 1)
	{
		params->out_num = ft_strjoin_free(&params->out_num, params->string);
		params->out_num = ft_strjoin_free(&params->out_num, params->out);
		ft_putstr(params->out_num);
	}
	else
	{
		params->out = ft_strjoin_free(&params->out, params->out_num);
		params->out = ft_strjoin_free(&params->out, params->string);
		ft_putstr(params->out);
	}
	ft_putchar('\n');
	free(params->string);
	free(*size);	
}

void	ft_check_no_size(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
	{
		size->i = (int)number;
		if (size->i < 0)
		{
			params->check_num = -1;
			size->i = -size->i;
		}
		params->string = ft_itoa_base((size_t)size->i, params->base, 0);
	}
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
			|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_i = (unsigned int)number;
		params->string = ft_itoa_base((size_t)size->u_i, params->base, (params->convers[0] == 'X' ? 1 : 0));
	}
	else if (!ft_strcmp(params->convers, "p"))
	{
		size->l = (long)number;
		if (size->l < 0)
		{
			params->check_num = -1;
			size->l = -size->l;
		}
		params->string = ft_itoa_base((size_t)size->l, params->base, 0);
		params->flag[0] = '#';
	}
}

void	ft_converse_numb(t_printf *params, void *number)
{
	t_size		*size;

	size = (t_size *)malloc(sizeof(t_size));
	params->check_num = 1;
	params->base = ft_find_base(params);
	if (ft_strcmp(params->size, ""))
		ft_check_size(params, size, number);
	else
		ft_check_no_size(params, size, number);
	ft_make_out(params->string, params);
	ft_print_num(params, &size);
}

void	ft_converse(t_printf *params, void *string)
{
	params->out = ft_strnew(0);
	params->out_num = ft_strnew(0);
	// if (params->convers[0] == '%')
	// 	ft_converse_per(params);
	// if (params->convers[0] == 's' || params->convers[0] == 'S')
	// 	ft_converse_string(params, (char *)string);
	if (params->convers[0] == 'i' || params->convers[0] == 'd' || params->convers[0] == 'u' 
		|| params->convers[0] == 'D' || params->convers[0] == 'U' 
		|| params->convers[0] == 'o' || params->convers[0] == 'O' || params->convers[0] == 'x' 
		|| params->convers[0] == 'X' || params->convers[0] == 'p')
		ft_converse_numb(params, string);
	// if (params->convers[0] == 'c' || params->convers[0] == 'C')
	// 	ft_converse_char(params, (char)string);
}