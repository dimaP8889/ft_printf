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

static void	ft_before_perc(const char **string, t_printf **params)
{
	if (!ft_strcmp(*string, "%"))
	{
		(*params)->found_perc = 0;
		(*params)->print = ft_strnew(1);
		(*params)->next = NULL;
		return ;
	}
	if (**string != '%')
	{
		(*params)->found_perc = 0;
	 	(*params)->print = ft_strnew(1);
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

static void	ft_set_params(t_printf *params)
{
	params->width = 0;
	params->precision = -1;
	params->found_perc = 0;
	params->base = 0;
	params->check_num = 0;
	params->return_val = 0;
	params->check_zero = 0;
	params->move = 0;
	params->tihs = 0;
	params->this_is_funny_o_sharp = 0;
	params->str_lenght = 0;
	params->flag = ft_strnew(1);
	params->convers = ft_strnew(1);
	params->size = ft_strnew(1);
	params->precision_char = ft_strnew(1);
	params->width_char = ft_strnew(1);
	params->print = ft_strnew(1);
	params->string = ft_strnew(1);
	params->out = ft_strnew(1);
	params->out_num = ft_strnew(1);
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