#include "ft_printf.h"

void	ft_free(t_printf *list)
{
	if (list->found_perc == 1)
	{
		while (list->next)
		{
			//printf("print: %s\n", list->print);
			//printf("pars: %s\n", list->pars);
			free(list->pars);
			free(list->print);
			free(list->flag);
			free(list->width_char);
			free(list->precision_char);
			free(list->size);
			free(list->convers);
			free(list->out);
			free(list->out_num);
			free(list);
			list = list->next;
		}
	}
	else
	{
		printf("print: %s\n", list->print);
		free(list->print);
		free(list);
	}
	system("leaks ft_printf");
}

int		ft_printf(const char *string, ...)
{
	va_list 		ap;
	void			*s;
	t_printf		*params;
	t_printf		*list;

	params = (t_printf *)malloc(sizeof(t_printf));
	list = params;
	ft_find_params(string, params);
	va_start(ap, string);
	s = va_arg(ap, void*);
	ft_converse(list, s);
	//printf("%c\n", params->convers[0]);
	//ft_converse(params, s);
	va_end(ap);
	ft_free(params);
	return (0);
}

int		main(void)
{
	char lol;

	lol = -99;
	ft_printf("% 5.3hhi", lol);
}