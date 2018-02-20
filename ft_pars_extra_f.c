#include "ft_printf.h"

void	ft_find_convers(const char **string, t_printf *params)
{
	while (**string == ' ' && *string)
		(*string)++;
	if (ft_strchr(CONVERS, **string) && **string)
	{
		params->convers = ft_addletter(params->convers, **string);
		(*string)++;
	}
	else if (**string)
	{
		params->out_num = ft_addletter(params->out_num, **string);
		(*string)++;
	}
}

void	ft_choose_size(int max, t_printf *params)
{
	if (max >= 0)
	{
		if (max == 0)
			params->size = ft_addletter(params->size, 'h');
		if (max == 1)
		{
			params->size = ft_addletter(params->size, 'h');
			params->size = ft_addletter(params->size, 'h');
		}
		if (max == 2)
			params->size = ft_addletter(params->size, 'l');
		if (max == 3)
		{
			params->size = ft_addletter(params->size, 'l');
			params->size = ft_addletter(params->size, 'l');
		}
		if (max == 4)
			params->size = ft_addletter(params->size, 'j');
		if (max == 5)
			params->size = ft_addletter(params->size, 'z');
	}
}

int	check_size_base(const char *string)
{
	int		count;

	count = 0;
	while (SIZES[count] != string[0])
		count++;
	if ((string[0] == 'h') || (string[0] == 'l'))
	{
		if (SIZES[count] == string[1])
			count++;
	}
	return (count);
}