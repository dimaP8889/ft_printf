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

void	ft_flag_sharp(t_printf *params, t_flags_num *flag)
{
	int		count;

	count = 0;
	if (!ft_strcmp(params->convers, "o") && !params->check_zero 
		&& (int)ft_strlen(params->string) >= params->precision)
		flag->sharp_o = 1;
	else if (!ft_strcmp(params->convers, "o"))
		params->this_is_funny_o_sharp = 1;
	else if ((!ft_strcmp(params->convers, "x")) && !params->check_zero)
		flag->sharp_x = 1;
	else if (!ft_strcmp(params->convers, "p"))
		flag->sharp_p = 1;
	else if (!ft_strcmp(params->convers, "X") && !params->check_zero)
		flag->sharp_X = 1;
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