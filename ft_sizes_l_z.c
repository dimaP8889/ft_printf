/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:18:24 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/05 19:18:25 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_size_l_d_i_D(t_printf *params, t_size *size, void *number)
{
	size->l = (long)number;
	if (!size->l)
		params->check_zero = 1;
	if (size->l < 0)
	{
		params->check_num = -1;
		size->l = -size->l;
	}
	if (!ft_strcmp(params->convers, "D"))
		params->convers[0] = 'd';
	free(params->string);
	params->string = ft_itoa_base((size_t)size->l, params->base, 0);
}

void	ft_check_size_l(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->convers, "d") 
		|| !ft_strcmp(params->convers, "i") || !ft_strcmp(params->convers, "D"))
		ft_check_size_l_d_i_D(params, size, number);
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "O")
		|| !ft_strcmp(params->convers, "u") || !ft_strcmp(params->convers, "U")
		|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_l = (unsigned long)number;
		if (!size->u_l)
			params->check_zero = 1;
		free(params->string);
		if (!ft_strcmp(params->convers, "O"))
			params->convers[0] = 'o';
		if (!ft_strcmp(params->convers, "U"))
			params->convers[0] = 'u';
		params->string = ft_itoa_base((size_t)size->u_l, 
		params->base, (params->convers[0] == 'X' ? 1 : 0));
	}
}

void	ft_check_size_ll(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
	{
		size->ll = (long long)number;
		if (!size->ll)
			params->check_zero = 1;
		if (size->ll < 0)
		{
			params->check_num = -1;
			size->ll = -size->ll;
		}
		free(params->string);
		params->string = ft_itoa_base((size_t)size->ll, params->base, 0);
	}
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
		|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_ll = (unsigned long long)number;
		if (!size->u_ll)
			params->check_zero = 1;
		free(params->string);
		params->string = ft_itoa_base((size_t)size->u_ll, 
		params->base, (params->convers[0] == 'X' ? 1 : 0));
	}
}

void	ft_check_size_j(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
	{
		size->j = (intmax_t)number;
		if (!size->j)
			params->check_zero = 1;
		if (size->j < 0)
		{
			params->check_num = -1;
			size->j = -size->j;
		}
		free(params->string);
		params->string = ft_itoa_base((size_t)size->j, params->base, 0);
	}
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
		|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_j = (uintmax_t)number;
		if (!size->u_j)
			params->check_zero = 1;
		free(params->string);
		params->string = ft_itoa_base((size_t)size->u_j, 
		params->base, (params->convers[0] == 'X' ? 1 : 0));
	}
}

void	ft_check_size_z(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
	{
		size->z = (ssize_t)number;
		if (!size->z)
			params->check_zero = 1;
		if (size->z < 0)
		{
			params->check_num = -1;
			size->z = -size->z;
		}
		free(params->string);
		params->string = ft_itoa_base((size_t)size->z, params->base, 0);
	}
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
		|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_z = (size_t)number;
		if (!size->u_z)
			params->check_zero = 1;
		free(params->string);
		params->string = ft_itoa_base((size_t)size->u_z, 
		params->base, (params->convers[0] == 'X' ? 1 : 0));
	}
}
