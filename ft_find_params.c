#include "ft_printf.h"

char	*ft_strjoin_free(char **s1, char const *s2)
{
	char	*str;
	char	*str1;
	char	*help_str;

	if (*s1 && s1 && s2)
	{
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


char	*ft_find_flag(const char **string, t_printf *params)
{
	params->flag = ft_strnew(0);
	while (ft_strchr(FLAGS, **string))
	{
		params->flag = ft_addletter(params->flag, **string);
		(*string)++;
		if (ft_strchr(params->flag, **string))
			break ;
	}
	return (params->flag);
}

char	*ft_find_width(const char **string, t_printf *params)
{
	params->width_char = ft_strnew(0);
	while (ft_isdigit(**string))
	{
		params->width_char = ft_addletter(params->width_char, **string);
		(*string)++;
	}
	params->width = ft_atoi(params->width_char);
	return (params->width_char);
}

char	*ft_find_precision(const char **string, t_printf *params)
{
	params->precision_char = ft_strnew(0);
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
	return (params->precision_char);
}

char	*ft_find_size(const char **string, t_printf *params)
{
	char	str;

	params->size = ft_strnew(0);
	if (ft_strchr(SIZES, **string))
	{
		str = **string;
		params->size = ft_addletter(params->size, **string);
		(*string)++;
		if ((**string == 'h' && str == 'h') || (**string == 'l' && str == 'l'))
		{
			params->size = ft_addletter(params->size, **string);
			(*string)++;
		}
	}
	return (params->size);
}

char	*ft_find_convers(const char **string, t_printf *params)
{
	params->convers = (char *)malloc(sizeof(char));
	params->convers = ft_memset((void *)params->convers, '\0', 1);
	if (ft_strchr(CONVERS, **string))
	{
		params->convers = ft_addletter(params->convers, **string);
		(*string)++;
	}
	return (params->convers);
}

char	*ft_pars(const char **string, t_printf *params)
{
	params->print = ft_strnew(0);
	while (**string != '%')
	{
		if (!(**string))
			return (NULL);
		params->print = ft_addletter(params->print, **string);
		(*string)++;
	}
	(*string)++;
	params->pars = (char *)malloc(sizeof(char));
	ft_strcpy(params->pars, "%");
	params->pars = ft_strjoin_free(&params->pars, ft_find_flag(string, params));
	params->pars = ft_strjoin_free(&params->pars, ft_find_width(string, params));
	params->pars = ft_strjoin_free(&params->pars, ft_find_precision(string, params));
	params->precision_char++;
	params->precision = ft_atoi(params->precision_char);
	params->precision_char--;
	params->pars = ft_strjoin_free(&params->pars, ft_find_size(string, params));
	params->pars = ft_strjoin_free(&params->pars, ft_find_convers(string, params));
	return (params->pars);
}

char	ft_find_params(const char *string)
{
	t_printf		*params;
	t_printf		*list;

	params = (t_printf *)malloc(sizeof(t_printf));
	list = params;
	while (ft_strchr(string, '%'))
	{
		ft_pars(&string, params);
		params->next = (t_printf *)malloc(sizeof(t_printf));
		params = params->next;
		params->next = NULL;
	}
	while (list->next)
	{
		printf("start\n");
		printf("%s\n", list->print);
		printf("%s\n", list->pars);
		printf("%s\n", list->flag);
		printf("%s\n", list->precision_char);
		printf("%s\n", list->width_char);
		printf("%s\n", list->convers);
		printf("%s\n", list->size);
		printf("%i\n", list->precision);
		printf("%i\n", list->width);
		printf("end\n");
		printf("\n");
		free(list->pars);
		free(list->print);
		free(list->flag);
		free(list->width_char);
		free(list->precision_char);
		free(list->size);
		free(list->convers);
		free(list);
		list = list->next;
	}
	system("leaks ft_printf");
	return(0);
}