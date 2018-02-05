/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converse_numb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:15:17 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/05 19:15:18 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_size(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->size, "l") || !ft_strcmp(params->convers, "D") 
		|| !ft_strcmp(params->convers, "U") || !ft_strcmp(params->convers, "O"))
		ft_check_size_l(params, size, number);
	else if (!ft_strcmp(params->size, "hh"))
		ft_check_size_hh(params, size, number);
	else if (!ft_strcmp(params->size, "h"))
		ft_check_size_h(params, size, number);
	else if (!ft_strcmp(params->size, "ll"))
		ft_check_size_ll(params, size, number);
	else if (!ft_strcmp(params->size, "j"))
		ft_check_size_j(params, size, number);
	else if (!ft_strcmp(params->size, "z"))
		ft_check_size_z(params, size, number);
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

void	ft_make_out(char *string, t_printf *params)
{
	int			count_perc;
	int 		length;
	int			count;

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
	count = length;
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
	{
		params->out = ft_addletter(params->out, '-');
		// if (ft_strcmp(params->out, ""))
		// {
		// 	params->out_num = ft_addletter(params->out_num, '-');
		// }
	}
}

