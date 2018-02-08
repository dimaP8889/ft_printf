#include "ft_printf.h"

void	ft_free(t_printf *list)
{
	if (list->found_perc == 1)
	{
		while (list->next)
		{
			free(list->pars);
			free(list->print);
			free(list->flag);
			free(list->width_char);
			free(list->precision_char);
			free(list->size);
			free(list->convers);
			list->out_num = list->out_num - list->move;
			free(list->out);
			free(list->out_num);
			free(list);
			list = list->next;
		}
	}
	else
	{
		//printf("print: %s\n", list->print);
		free(list->print);
		free(list);
	}
	//system("leaks ft_printf");
}

int		ft_find_base_flags(char c)
{
	int		num;
	char 	*base;

	base = "0+ #-\0";
	num = 0;
	while (base[num] != c)
		num++;
	return (num);
}

void	ft_sort_flags(t_printf *params)
{
	int		count_flags;
	char 	flag;

	count_flags = 0;
	//printf("%s\n", params->flag);
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

int		ft_printf(const char *string, ...)
{
	va_list 		ap;
	void			*s;
	t_printf		*params;
	t_printf		*list;

	params = (t_printf *)malloc(sizeof(t_printf));
	list = params;
	if (!ft_find_params(string, params))
	{
		ft_putstr(params->print);
		return (ft_strlen(params->print));
	}
	ft_sort_flags(params);
	va_start(ap, string);
	s = va_arg(ap, void*);
	ft_converse(list, s);
	//printf("%c\n", params->convers[0]);
	//ft_converse(params, s);
	va_end(ap);
	ft_free(params);
	return (params->return_val);
}

// int		main(void)
// {
// 	int lol;

// 	lol = -13;
// 	ft_printf("% 2i", lol);
// }