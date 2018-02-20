#include "ft_printf.h"

static void	ft_check_size_hh_d_i(t_printf *params, t_size *size, void *number)
{
	size->hh = (signed char)number;
	if (!size->hh)
		params->check_zero = 1;
	if (size->hh == -128)
	{
		params->check_num = -1;
		params->string = ft_strjoin_free(&params->string, "128");
	}
	else
	{
		if (size->hh < 0)
		{
			params->check_num = -1;
			size->hh = -size->hh;
		}
		free(params->string);
		params->string = ft_itoa_base((size_t)size->hh, params->base, 0);
	}
}

void	ft_check_size_hh(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
		ft_check_size_hh_d_i(params, size, number);
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
		|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_hh = (unsigned char)number;
		if (!size->u_hh)
			params->check_zero = 1;
		if (size->u_hh < 0)
		{
			params->check_num = -1;
			size->u_hh = -size->u_hh;
		}
		free(params->string);
		params->string = ft_itoa_base((size_t)size->u_hh, 
		params->base, (params->convers[0] == 'X' ? 1 : 0));
	}
}

static void	ft_check_size_h_d_i(t_printf *params, t_size *size, void *number)
{
	size->h = (short)number;
	if (!size->h)
		params->check_zero = 1;
	if (size->h == -32768)
	{
		params->check_num = -1;
		params->string = ft_strjoin_free(&params->string, "32768");
	}
	else
	{
		if (size->h < 0)
		{
			params->check_num = -1;
			size->h = -size->h;
		}
		free(params->string);
		params->string = ft_itoa_base((size_t)size->h, params->base, 0);
	}
}

void	ft_check_size_h(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
		ft_check_size_h_d_i(params, size, number);
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
		|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_h = (unsigned short)number;
		if (!size->u_h)
			params->check_zero = 1;
		if (size->u_h < 0)
		{
			params->check_num = -1;
			size->u_h = -size->u_h;
		}
		free(params->string);
		params->string = ft_itoa_base((size_t)size->u_h, 
		params->base, (params->convers[0] == 'X' ? 1 : 0));
	}
}