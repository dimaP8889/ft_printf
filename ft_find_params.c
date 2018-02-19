#include "ft_printf.h"

char	*ft_strjoin_free(char **s1, char const *s2)
{
	char	*str;
	char	*str1;
	char	*help_str;

	if (s1 && s2)
	{
		if (!*s1)
			help_str = ft_strnew(0);
		else
			help_str = ft_strdup(*s1);
		str = (char *)malloc(sizeof(char)
			* (ft_strlen(help_str) + ft_strlen(s2) + 1));
		if (str == NULL)
			return (NULL);
		str1 = str;
		str = ft_strcpy(str, (char *)help_str);
		str = ft_strcat(str, (char *)s2);
		free(*s1);
		free(help_str);
		return (str);
	}
	return (0);
}


void	ft_find_flag(const char **string, t_printf *params)
{
	if (**string == ' ')
	{
		params->flag = ft_addletter(params->flag, **string);
		(*string)++;
	}
	while (**string == ' ')
		(*string)++;
	while (ft_strchr(FLAGS, **string) && **string)
	{
		if (!ft_strchr(params->flag, **string))
			params->flag = ft_addletter(params->flag, **string);
		(*string)++;
	}
}

void	ft_find_width(const char **string, t_printf *params)
{
	while (**string == ' ')
		(*string)++;
	while (ft_isdigit(**string))
	{
		params->width_char = ft_addletter(params->width_char, **string);
		(*string)++;
	}
	params->width = ft_atoi(params->width_char);
}

void	ft_find_precision(const char **string, t_printf *params)
{
	while (**string == ' ')
		(*string)++;
	if (**string == '.')
	{
		(*string)++;
		ft_strcpy(params->precision_char, ".");
		while (ft_isdigit(**string))
		{
			params->precision_char = ft_addletter(params->precision_char, **string);
			(*string)++;
		}
	}
	params->precision_char++;
	params->precision = ft_atoi(params->precision_char);
	params->precision_char--;
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

void	ft_find_size(const char **string, t_printf *params)
{

	int		max;
	int		base;

	max = -1;
	while (**string == ' ')
		(*string)++;
	while (ft_strchr(SIZES, **string) && **string)
	{
		base = check_size_base(*string);
		if  (base > max)
			max = base;
		(*string)++;
	}
	ft_choose_size(max, params);
}

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

void	ft_pars(const char **string, t_printf *params)
{
	while (!ft_strchr(CONVERS, **string) && **string)
	{
		if (ft_strchr(FLAGS, **string))
			ft_find_flag(string, params);
		else if (**string == '.')
			ft_find_precision(string, params);
		else if (ft_strchr(SIZES, **string))
			ft_find_size(string, params);
		else if (ft_isdigit((**string - 0)))
			ft_find_width(string, params);
		else
			break ;
	}
	ft_find_convers(string, params);
}

void	ft_before_perc(const char **string, t_printf **params)
{
	if (!ft_strcmp(*string, "%"))
	{
		(*params)->found_perc = 0;
		(*params)->print = ft_strnew(0);
		(*params)->next = NULL;
		return ;
	}
	if (**string != '%')
	{
		(*params)->found_perc = 0;
	 	(*params)->print = ft_strnew(0);
	 	while (**string && **string != '%')
		{
			(*params)->print = ft_addletter((*params)->print, **string);
			(*string)++;
			(*params)->return_val++;
		}
		if (**string == '%')
		{
			(*params)->next = (t_printf *)malloc(sizeof(t_printf));
			(*params) = (*params)->next;
	 		(*params)->next = NULL;
		}
	}
}

void	ft_find_params(const char *string, t_printf *params)
{
	params->next = NULL;
	ft_before_perc(&string, &params);
	while (ft_strchr(string, '%'))
	{
		ft_set_params(params);
		string++;
		ft_pars(&string, params);
		params->found_perc = 1;
		while (*string && *string != '%')
		{
			params->print = ft_addletter(params->print, *string);
			(string)++;
			params->return_val++;
		}
		if (*string == '%')
		{
			params->next = (t_printf *)malloc(sizeof(t_printf));
			params = params->next;
	 		params->next = NULL;
		}
	}
}