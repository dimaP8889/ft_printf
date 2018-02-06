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
	if (!ft_strcmp(params->precision_char, "") && !ft_strchr(params->flag, '-'))
	{
		while (params->out[flag->count_zer] == ' ')
		{
			if (params->check_num == -1)
			{
				params->out[0] = '-';
				flag->count_zer++;
				params->flag_zero++;
				params->check_num = 1;
				params->out = ft_addletter(params->out, '0');
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
		if (ft_strchr(params->flag, '-')) // NEED TO FIX
		{
			printf("test\n");
			params->out++;
			params->flag_p_m++;
			params->out_num[0] = '+';
		}
		else if (ft_strchr(params->flag, '0'))
		{
			if (!params->flag_zero)
				params->out[0] = '+';
			else
				params->out[0] = '-';
		}
		else if (ft_strcmp(params->out, ""))
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
	if (!ft_strcmp(params->convers, "o") && !params->check_zero)
	{
		if (((int)ft_strlen(string) >= params->precision))
		{
			if (ft_strchr(params->flag, '-'))
			{
				params->out_num[0] = '0';
				params->out++;
				params->flag_m_z = 1;
			}
			else if (ft_strcmp(params->out, ""))
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
	else if ((!ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "p")) && !params->check_zero)
	{
		while (params->out[flag->count_x])
			flag->count_x++;
		if (flag->count_x < 1)
		{
			flag->sharp = params->out_num;
			params->out_num = ft_strjoin("0x", flag->sharp);
			free(flag->sharp);
		}
		else if(ft_strchr(params->flag, '0') && !ft_strchr(params->flag, '-')) //|| ft_strchr(params->flag, '-'))
		{
			params->out[0] = '0';
			params->out[1] = 'x';
			flag->count_zer = flag->count_zer + 2;
		}
		else if (ft_strchr(params->flag, '-'))
		{
			params->out_num[0] = '0';
			params->out_num[1] = 'x';
			params->out++;
			params->out++;
			params->flag_m_z = 2;
		}
		else
		{
			while (params->out[flag->count_sharp + 2])
				flag->count_sharp++;
			params->out[flag->count_sharp] = '0';
			params->out[flag->count_sharp + 1] = 'x';
		}
	}
	else if (!ft_strcmp(params->convers, "X") && !params->check_zero)
	{
		while (params->out[flag->count_x])
			flag->count_x++;
		if (flag->count_x < 1)
		{
			flag->sharp = params->out_num;
			params->out_num = ft_strjoin("0X", flag->sharp);
			free(flag->sharp);
		}
		else if(ft_strchr(params->flag, '0') && !ft_strchr(params->flag, '-'))
		{
			params->out[0] = '0';
			params->out[1] = 'x';
			flag->count_zer = flag->count_zer + 2;
		}
		else if (ft_strchr(params->flag, '-'))
		{
			params->out_num[0] = '0';
			params->out_num[1] = 'x';
			params->out++;
			params->out++;
			params->flag_m_z = 2;
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
	flag->count_sharp = 0;
	flag->count_plus = 0;
	flag->count_x = 0;
}

void	ft_make_flag(t_printf *params, char *string)
{
	t_flags_num *flag;
	int			count;

	count = 0;
	params->flag_minus = 0;
	params->flag_zero = 0;
	params->flag_p_m = 0;
	flag = (t_flags_num *)malloc(sizeof(t_flags_num));
	flag->count_zer = 0;
	while (params->flag[count])
	{
		ft_set_flags(flag);
		if (params->flag[count] == '0')
			ft_flag_zero(params, flag);
		else if (params->flag[count] == ' ' && !ft_strchr(params->flag, '+'))
		{
			if ((params->check_num > 0
			&& ((int)ft_strlen(string) >= params->width)))
				params->out = ft_addletter(params->out, ' ');
			if (ft_strchr(params->flag, '0') && ft_strchr(params->flag, '0') > ft_strchr(params->flag, ' '))
				flag->count_zer++;
			if (ft_strchr(params->flag, '0') && ft_strchr(params->flag, '0') < ft_strchr(params->flag, ' '))
				params->out[0] = ' ';
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