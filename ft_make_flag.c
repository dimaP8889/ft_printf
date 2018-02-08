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

void	ft_add_letter(t_printf *params)
{
	if (params->check_num == -1)
		params->out = ft_addletter(params->out, '-');
	else if (params->flag_plus == 1)
		params->out = ft_addletter(params->out, '+');
	else if (params->flag_space == 1)
		params->out = ft_addletter(params->out, ' ');
	else if (params->flag_sharp_o == 1)
		params->out = ft_addletter(params->out, '0');
	else if (params->flag_sharp_x == 1)
	{
		params->out = ft_addletter(params->out, '0');
		params->out = ft_addletter(params->out, 'x');
	}
	else if (params->flag_sharp_X == 1)
	{
		params->out = ft_addletter(params->out, '0');
		params->out = ft_addletter(params->out, 'X');
	}
}

void	ft_add_out(t_printf *params, int x)
{
	int count;

	count = 0;
	while (params->out[count + x])
		count++;
	if (params->check_num == -1)
		params->out[count] = '-';
	else if (params->flag_plus == 1)
		params->out[count] = '+';
	else if (params->flag_space == 1)
		params->out[count] = ' ';
	else if (params->flag_sharp_o == 1)
		params->out[count] = '0';
	else if (params->flag_sharp_x == 1)
	{
		params->out[count] = '0';
		params->out[count + 1] = 'x';
	}
	else if (params->flag_sharp_X == 1)
	{
		params->out[count] = '0';
		params->out[count + 1] = 'X';
	}
}

void	ft_add_out_num(t_printf *params)
{
	if (params->check_num == -1)
		params->out_num[0] = '-';
	else if (params->flag_plus == 1)
		params->out_num[0] = '+';
	else if (params->flag_space == 1)
		params->out_num[0] = ' ';
	else if (params->flag_sharp_o == 1)
		params->out_num[0] = '0';
	else if (params->flag_sharp_x == 1)
	{
		params->out_num[0] = '0';
		params->out_num[1] = 'x';
	}
	else if (params->flag_sharp_X == 1)
	{
		params->out_num[0] = '0';
		params->out_num[1] = 'X';
	}
}

void	ft_swap_letters(t_printf *params)
{
	char 	x;
	char 	o;
	int		count;

	count = 0;
	if (params->flag_sharp_x == 1 || params->flag_sharp_X == 1)
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
	else if (params->flag_sharp_o == 1 || params->flag_space == 1 ||
	params->flag_plus == 1 || params->check_num == -1)
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
	(void)flag;

	count = 0;
	if (!ft_strcmp(params->precision_char, "") && !ft_strchr(params->flag, '-'))
	{
		while (params->out[count] == ' ')
		{
			params->out[count] = '0';
			count++;
		}
		zero = params->out;
		params->flag_zero = 1;
		params->out_num = ft_strjoin(zero, params->out_num);
		params->out = ft_memset(params->out, '\0', ft_strlen(params->out));
		//leak
	}
	
}

void	ft_flag_plus(t_printf *params, t_flags_num *flag)
{
	(void)flag;

	if (params->check_num == 1 && !ft_strchr(params->convers, 'u'))
		params->flag_plus = 1;
}

void	ft_flag_space(t_printf *params, t_flags_num *flag)
{
	(void)flag;

	if (!ft_strchr(params->flag, '+') && !ft_strchr(params->convers, 'u'))
		params->flag_space = 1;
}

void	ft_flag_minus(t_printf *params, t_flags_num *flag)
{
	(void)flag;
	char *str;

	str = params->out;
	params->out = params->out_num;
	params->out_num = str;
	ft_add_letter(params);
	ft_swap_letters(params);
	if (ft_strlen(params->out_num) != 0)
	{
		if (params->check_num == -1)
		{
			params->out_num++;
			params->move++;
		}
		else if (params->flag_plus == 1)
		{
			params->out_num++;
			params->move++;
		}
		else if (params->flag_space == 1)
		{
			params->out_num++;
			params->move++;
		}
		else if (params->flag_sharp_o == 1)
		{
			params->out_num++;
			params->move++;
		}
		else if (params->flag_sharp_x == 1 || params->flag_sharp_X == 1)
		{
			params->out_num = params->out_num + 2;
			params->move = params->move + 2;
		}
	}
}

void	ft_flag_sharp(t_printf *params, t_flags_num *flag)
{
	int		count;
	(void)flag;

	count = 0;
	if (!ft_strcmp(params->convers, "o") && !params->check_zero)
		params->flag_sharp_o = 1;
	else if ((!ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "p")) && !params->check_zero)
		params->flag_sharp_x = 1;
	else if (!ft_strcmp(params->convers, "X") && !params->check_zero)
		params->flag_sharp_X = 1;
}

void	ft_finish_flags(t_printf *params)
{
	int		x;

	x = 1;
	if (params->width <= params->precision 
		|| params->width <= (int)ft_strlen(params->string))
		ft_add_letter(params);
	else if (params->width > params->precision)
	{
		if (params->flag_sharp_x == 1 || params->flag_sharp_X == 1)
			x = 2;
		if (params->flag_zero == 0)
			ft_add_out(params, x);
		else
			ft_add_out_num(params);
	}
}

void	ft_make_flag(t_printf *params)
{
	t_flags_num *flag;
	int			count;

	count = 0;
	params->flag_minus = 0;
	params->flag_mv = 0;
	flag = (t_flags_num *)malloc(sizeof(t_flags_num));
	flag->count_zer = 0;
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
		ft_finish_flags(params);
	free(flag);
}