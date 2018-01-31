#include "ft_printf.h"


void	ft_converse_per(t_printf *params)
{
	ft_check_all(params, NULL);
	ft_addletter((char *)params->out, '%');
	ft_putstr((char *)params->out);
}

void	ft_converse_char(t_printf *params, char c)
{
	if(!ft_check_all(params, c))
		ft_addletter((char *)params->out, c);
	ft_putstr((char *)params->out);
}

void	ft_converse_string(t_printf *params, char *string)
{

	char 	*str_cpy;
	// char 	*str_help;

	str_cpy = (char *)params->out;
	// str_help = ft_strdup(string);
	// if ((size_t)params->precision < ft_strlen(string) && ft_strcmp(params->precision_char, ""))
	// {
	// 	str_help[params->precision] = '\0';
	// 	params->out = ft_strjoin(str_cpy, str_help);
	// }
	// else
	// 	params->out = ft_strjoin(str_cpy, string);
	// free(str_cpy);
	// free(str_help);
	if(!ft_check_all(params, string))
		params->out = ft_strjoin(str_cpy, params->out);
	ft_putstr((char *)params->out);
}
// переделать, фенкция check_all должна сразу же обрабатывать все

void	ft_converse(t_printf *params, void *string)
{
	params->out = ft_strnew(0);
	if (params->convers[0] == '%')
		ft_converse_per(params);
	if (params->convers[0] == 's' || params->convers[0] == 'S')
		ft_converse_string(params, (char *)string);
// 	if (params->converse == 'i' || params->converse == 'd' || params->converse == 'u' 
// 		|| params->converse == 'D' || || params->converse == 'U')
// 		ft_converse_numb(params, string);
// 	if (params->converse == 'o' || params->converse == 'O')
// 		ft_converse_oct(params, string);
// 	if (params->converse == 'x' || params->converse == 'X' || params->converse == 'p')
//		ft_converse_hex(params, string);
	if (params->convers[0] == 'c' || params->convers[0] == 'C')
		ft_converse_char(params, (char)string);
}