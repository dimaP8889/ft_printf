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

void	ft_check_size_z(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
	{
		size->z = (ssize_t)number;
		if (size->z < 0)
		{
			params->check_num = -1;
			size->z = -size->z;
		}
		params->string = ft_itoa_base((size_t)size->z, params->base, 0);
	}
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
		|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_z = (size_t)number;
		params->string = ft_itoa_base((size_t)size->u_z, 
		params->base, (params->convers[0] == 'X' ? 1 : 0));
	}
}
