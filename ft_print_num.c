/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:17:23 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/05 19:17:24 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num(t_printf *params)
{
	int 	count;

	count = 0;
	params->out = ft_strjoin_free(&params->out, params->out_num);
	if (!params->precision && params->check_zero 
	&& !params->this_is_funny_o_sharp && ft_strcmp(params->convers, "p"))
	{
		while (params->out[count] != '0')
			count++;
		if (params->out[count - 1] == '+')
			params->out[count] = '+';
		else
			params->out[count] = ' ';
		if (params->width < 1)
		{
			params->out++;
			params->tihs = 1;
		}
	}
	ft_putstr(params->out);
	params->return_val = ft_strlen(params->out) + ft_strlen(params->print);
}