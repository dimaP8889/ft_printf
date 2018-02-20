#include "ft_printf.h"

static void	ft_free(t_printf *list)
{
	while (list)
	{
		if (list->found_perc == 0)
		{
			free(list->print);
			free(list);
		}
		else
		{
			free(list->print);
			free(list->flag);
			free(list->width_char);
			free(list->precision_char);
			free(list->size);
			free(list->convers);
			free(list->string);
			list->out_num = list->out_num - list->move;
			list->out = list->out - list->tihs;
			free(list->out);
			free(list->out_num);
			free(list);
		}
		list = list->next;
	}
}

static int		ft_find_base_flags(char c)
{
	int		num;
	char 	*base;

	base = "0+ #-\0";
	num = 0;
	while (base[num] != c)
		num++;
	return (num);
}

static void	ft_sort_flags(t_printf *params)
{
	int		count_flags;
	char 	flag;

	count_flags = 0;
	while (params->flag[count_flags + 1])
	{
		if (ft_find_base_flags(params->flag[count_flags]) > ft_find_base_flags(params->flag[count_flags + 1]))
		{
			flag = params->flag[count_flags];
			params->flag[count_flags] = params->flag[count_flags + 1];
			params->flag[count_flags + 1] = flag;
		}
		count_flags++;
	}
}

static void	ft_printf_params(t_printf *params, int *ret, va_list ap)
{
	void			*s;

	s = NULL;
	ft_sort_flags(params);
	if (ft_strcmp(params->convers, "") && ft_strcmp(params->convers, "%"))
		s = va_arg(ap, void*);
	ft_converse(params, s);
	ft_putstr(params->print);
	*ret = *ret + params->return_val;
}

int		ft_printf(const char *string, ...)
{
	va_list 		ap;
	int				ret;
	t_printf		*params;
	t_printf		*list;

	ret = 0;
	if (!(params = (t_printf *)malloc(sizeof(t_printf))))
		return (0);
	list = params;
	ft_find_params(string, params);
	va_start(ap, string);
	if (params->found_perc == 0)
	{
		ft_putstr(params->print);
		ret = ret + ft_strlen(params->print);
		params = params->next;
	}
	while (params)
	{
		ft_printf_params(params, &ret, ap);
		params = params->next;
	}
	ft_free(list);
	va_end(ap);
	return (ret);
}
