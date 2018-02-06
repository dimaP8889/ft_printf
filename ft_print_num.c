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
	if (params->flag_minus == 1)
	{
		params->out_num = ft_strjoin_free(&params->out_num, params->string);
		params->out_num = ft_strjoin_free(&params->out_num, params->out);
		ft_putstr(params->out_num);
		params->return_val = ft_strlen(params->out_num);

	}
	else
	{
		params->out = ft_strjoin_free(&params->out, params->out_num);
		params->out = ft_strjoin_free(&params->out, params->string);
		ft_putstr(params->out);
		params->return_val = ft_strlen(params->out);
	}
	//ft_putchar('\n');
	free(params->string);
	free(*size);	
}