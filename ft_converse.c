#include "ft_printf.h"

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

void	ft_converse_numb(t_printf *params, void *number)
{
	t_size		*size;

	size = (t_size *)malloc(sizeof(t_size));
	params->check_num = 1;
	params->base = ft_find_base(params);
	if (ft_strcmp(params->size, "") || !ft_strcmp(params->convers, "D") 
		|| !ft_strcmp(params->convers, "U") || !ft_strcmp(params->convers, "O"))
		ft_check_size(params, size, number);
	else
		ft_check_no_size(params, size, number);
	ft_make_out(params->string, params);
	ft_print_num(params, &size);
}

void	ft_converse(t_printf *params, void *string)
{
	params->out = ft_strnew(0);
	params->out_num = ft_strnew(0);
	if ((int) string == 0)
		params->check_zero = 1;
	// if (params->convers[0] == '%')
	// 	ft_converse_per(params);
	// if (params->convers[0] == 's' || params->convers[0] == 'S')
	// 	ft_converse_string(params, (char *)string);
	if (params->convers[0] == 'i' || params->convers[0] == 'd' || params->convers[0] == 'u' 
		|| params->convers[0] == 'D' || params->convers[0] == 'U' 
		|| params->convers[0] == 'o' || params->convers[0] == 'O' || params->convers[0] == 'x' 
		|| params->convers[0] == 'X' || params->convers[0] == 'p')
		ft_converse_numb(params, string);
	// if (params->convers[0] == 'c' || params->convers[0] == 'C')
	// 	ft_converse_char(params, (char)string);
}