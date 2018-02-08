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

void	ft_print_num(t_printf *params, t_size **size)
{
	int 	count;

	count = 0;
	params->out = ft_strjoin_free(&params->out, params->out_num);
	if ((!ft_strcmp(params->precision_char, ".") || !ft_strcmp(params->precision_char, ".0")) && ft_atoi(params->string) == 0)
	{
		while (params->out[count] != '0')
			count++;
		params->out[count] = ' ';
	}
	if ((!ft_strcmp(params->precision_char, ".0") || !ft_strcmp(params->precision_char, ".0")) && ft_atoi(params->string) == 0)
	{
		while (params->out[count] != '0')
			count++;
		params->out++;
		params->tihs = 1;
	}
	ft_putstr(params->out);
	params->return_val = ft_strlen(params->out) + ft_strlen(params->print);
	free(*size);
}