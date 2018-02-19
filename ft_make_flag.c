/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:21:25 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/05 19:21:26 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (flag->sharp_X == 1)
	{
		params->out = ft_addletter(params->out, '0');
		params->out = ft_addletter(params->out, 'X');
	}
}

void	ft_add_out(t_printf *params, int x, t_flags_num *flag)
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
	else if (flag->sharp_X == 1)
	{
		params->out[count] = '0';
		params->out[count + 1] = 'X';
	}
}
void	ft_add_out_num(t_printf *params, t_flags_num *flag)
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
	else if (flag->sharp_X == 1)
	{
		params->out_num[0] = '0';
		params->out_num[1] = 'X';
	}
}

void	ft_swap_letters(t_printf *params, t_flags_num *flag)
{
	char 	x;
	char 	o;
	int		count;

	count = 0;
	if (flag->sharp_x == 1 || flag->sharp_X == 1 || flag->sharp_p == 1)
	{
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
	else if (flag->sharp_o == 1 || flag->space == 1 ||
	flag->plus == 1 || params->check_num == -1)
	{
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
}

void	ft_flag_zero(t_printf *params, t_flags_num *flag)
{
	char 	*zero;
	int		count;

	count = 0;
	if ((!ft_strcmp(params->precision_char, "") || !params->check_num) && !ft_strchr(params->flag, '-'))
	{
		while (params->out[count] == ' ')
		{
			params->out[count] = '0';
			count++;
		}
		zero = params->out_num;
		flag->zero = 1;
		params->out_num = ft_strjoin(params->out, zero);
		free(zero);
		params->out = ft_memset(params->out, '\0', ft_strlen(params->out));
	}
	
}

void	ft_flag_plus(t_printf *params, t_flags_num *flag)
{
	if (params->check_num == 1 && !ft_strchr(params->convers, 'u') 
		&& !ft_strchr(params->convers, 'o') && !ft_strchr(params->convers, 'X')
		&& !ft_strchr(params->convers, 'x') && !ft_strchr(params->convers, 'p'))
		flag->plus = 1;
}

void	ft_flag_space(t_printf *params, t_flags_num *flag)
{
	if (!ft_strchr(params->flag, '+') && !ft_strchr(params->convers, 'u') 
		&& !ft_strchr(params->convers, '%') && !ft_strchr(params->convers, 'o') 
		&& !ft_strchr(params->convers, 'X') && !ft_strchr(params->convers, 'x') 
		&& !ft_strchr(params->convers, 'p') && ft_strcmp(params->convers, "") 
		&& params->check_num)
	{
		flag->space = 1;
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
}

void	ft_flag_sharp(t_printf *params, t_flags_num *flag)
{
	int		count;

	count = 0;
	if (!ft_strcmp(params->convers, "o") && !params->check_zero 
		&& (int)ft_strlen(params->string) >= params->precision)
	{
		flag->sharp_o = 1;
	}
	else if (!ft_strcmp(params->convers, "o"))
	{
		params->this_is_funny_o_sharp = 1;
	}
	else if ((!ft_strcmp(params->convers, "x")) && !params->check_zero)
		flag->sharp_x = 1;
	else if (!ft_strcmp(params->convers, "p"))
		flag->sharp_p = 1;
	else if (!ft_strcmp(params->convers, "X") && !params->check_zero)
		flag->sharp_X = 1;
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

void	ft_make_flag(t_printf *params)
{
	t_flags_num *flag;

	if (!(flag = (t_flags_num*)malloc(sizeof(t_flags_num))))
		return ;
	ft_set_flags(flag);
	params->move = 0;
	if (ft_strchr(params->flag, '0'))
		ft_flag_zero(params, flag);
	if (ft_strchr(params->flag, '+'))
		ft_flag_plus(params, flag);
	if (ft_strchr(params->flag, ' '))
		ft_flag_space(params, flag);
	if (ft_strchr(params->flag, '#'))
		ft_flag_sharp(params, flag);
	if (ft_strchr(params->flag, '-'))
		ft_flag_minus(params, flag);
	else
		ft_finish_flags(params, flag);
	free(flag);
}