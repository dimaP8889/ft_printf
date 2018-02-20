#include "ft_printf.h"

void ft_no_converse(t_printf *params)
{
	int count_width;

	count_width = 0;
	count_width = params->width;
	while (count_width-- > 1)
		params->out = ft_addletter(params->out, ' ');
	ft_make_flag(params);
	params->out = ft_strjoin_free(&params->out, params->out_num);
	params->return_val = ft_strlen(params->out) + ft_strlen(params->print);
	ft_putstr(params->out);
}

void	ft_s_converse_string(t_printf *params, void *string, int count_prec)
{
	char 	*str1;
	int		count;

	count = 0;
	str1 = (char *)string;
	if (!string)
		str1 = ft_strjoin_free(&str1, "(null)");
	while (count_prec > 0 && str1[count])
	{
		params->out_num = ft_addletter(params->out_num, str1[count]);
		count++;
		params->str_lenght++;
		if (ft_strcmp(params->precision_char, ""))
			count_prec--;
	}
	if (!string)
		free(str1);
}

void	ft_l_converse_string(t_printf *params, void *string, int count_prec)
{
	unsigned int	*str;
	int				change;
	int				length;
	int				count;

	count = 0;
	change = 0;
	str = (unsigned int *)string;
	while (*str && count_prec > 0)
	{
		length = params->str_lenght;
		ft_make_unicode_char(params, *str);
		if (ft_strcmp(params->precision_char, ""))
		{
			change = params->str_lenght - length;
			count_prec -= change;
		}
		str++;
	}
	if (count_prec < 0)
		ft_cut_str(params, count_prec);
}

void	ft_cut_str(t_printf *params, int count_prec)
{
	int				count;

	count = 0;
	while (params->out_num[count + 1])
		count++;
	while (count_prec++ <= 0)
	{
		params->out_num[count--] = '\0';
		params->str_lenght--;
	}
}

int		ft_find_base(t_printf *params)
{
	if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "O"))
		return (8);
	else if (!ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X")
	|| !ft_strcmp(params->convers, "p"))
		return (16);
	else
		return (10);
}
