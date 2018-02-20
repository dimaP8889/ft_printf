#include "ft_printf.h"

static void	ft_converse_numb(t_printf *params, void *number)
{
	t_size		*size;

	if (!(size = (t_size *)malloc(sizeof(t_size))))
		return ;
	params->check_num = 1;
	params->base = ft_find_base(params);
	if ((ft_strcmp(params->size, "") || !ft_strcmp(params->convers, "D") 
		|| !ft_strcmp(params->convers, "U") || !ft_strcmp(params->convers, "O")) 
		&& ft_strcmp(params->convers, "p"))
		ft_check_size(params, size, number);
	else
		ft_check_no_size(params, size, number);
	ft_make_out(params);
	ft_print_num(params);
	free(size);
}

static void	ft_converse_char(t_printf *params, void *number)
{
	int	count;

	if ((!ft_strcmp(params->size, "l") || !ft_strcmp(params->convers, "C")) && MB_CUR_MAX == 4)
		ft_make_unicode_char(params, (unsigned int)number);
	else
	{
		params->str_lenght = params->str_lenght + 1;
		params->out_num = ft_addletter(params->out_num, (unsigned char) number);
	}
	count = params->width - params->str_lenght;
	while (count-- >= 1)
	{
		params->out = ft_addletter(params->out, ' ');
		params->return_val++;
	}
	ft_make_flag(params);
	params->out = ft_strjoin_free(&params->out, params->out_num);
	if (!(unsigned int)number && ft_strrchr(params->flag, '-'))
		ft_putchar('\0');
	ft_putstr(params->out);
	if (!(unsigned int)number && !ft_strrchr(params->flag, '-'))
		ft_putchar('\0');
	params->return_val += params->str_lenght;
}

static void	ft_converse_string(t_printf *params, void *string)
{
	int	count_width;
	int	count_prec;

	if (ft_strcmp(params->precision_char, ""))
		count_prec = params->precision;
	else
		count_prec = 1;
	if ((!ft_strcmp(params->size, "l") || !ft_strcmp(params->convers, "S")) 
	&& string)
		ft_l_converse_string(params, string, count_prec);
	else
		ft_s_converse_string(params, string, count_prec);
	count_width = params->width - params->str_lenght;
	while (count_width-- >= 1)
	{
		params->out = ft_addletter(params->out, ' ');
		params->return_val++;
	}
	ft_make_flag(params);
	params->out = ft_strjoin_free(&params->out, params->out_num);
	ft_putstr(params->out);
	params->return_val = params->str_lenght + params->return_val;
}

static void	ft_converse_per(t_printf *params)
{
	int	count;

	count = params->width;
	while (count-- > 1)
	{
		params->out = ft_addletter(params->out, ' ');
		params->return_val++;
	}
	params->return_val++;
	params->out_num = ft_addletter(params->out_num, '%');
	ft_make_flag(params);
	params->out = ft_strjoin_free(&params->out, params->out_num);
	ft_putstr(params->out);
}

void	ft_converse(t_printf *params, void *string)
{
	if (params->convers[0] == '%')
		ft_converse_per(params);
	else if (params->convers[0] == 's' || params->convers[0] == 'S')
		ft_converse_string(params, string);
	else if (params->convers[0] == 'i' || params->convers[0] == 'd' || params->convers[0] == 'u' 
		|| params->convers[0] == 'D' || params->convers[0] == 'U' 
		|| params->convers[0] == 'o' || params->convers[0] == 'O' || params->convers[0] == 'x' 
		|| params->convers[0] == 'X' || params->convers[0] == 'p')
		ft_converse_numb(params, string);
	else if (params->convers[0] == 'c' || params->convers[0] == 'C')
		ft_converse_char(params, string);
	else
		ft_no_converse(params);
}
