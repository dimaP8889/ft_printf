#include "ft_printf.h"

void	ft_converse_numb(t_printf *params, void *num)
{
	long long	number;
	int			count_perc;
	int 		count_width;
	int			check_num;
	int			base;
	char 		*string;
	t_size		*size;

	number = (long long)num;
	count_width = params->width;
	count_perc = params->precision;
	size = (t_size *)malloc(sizeof(t_size));

	if (number > 0)
		check_num = 1;
	else
	{
		check_num = -1;
		number = -number;
	}
	if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "O"))
		base = 8;
	else if (!ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X") || 
		!ft_strcmp(params->convers, "p"))
		base = 16;
	else
		base = 10;
	// string = ft_itoa_base((size_t)number, base, 1);
	// if (ft_strcmp(params->width_char, ""))
	// 	while (count_width > (int)ft_strlen(string) 
	// 		+ params->precision + (check_num == 1 ? 1 : 0))
	// 	{
	// 		params->out = ft_addletter(params->out, ' ');
	// 		count_width--;
	// 	}
	// if (check_num == -1)
	// 	params->out = ft_addletter(params->out, '-');
	// if (ft_strcmp(params->precision_char, ""))
	// 	while (count_perc > (int)ft_strlen(string))
	// 	{
	// 		params->out = ft_addletter(params->out, '0');
	// 		count_perc--;
	// 	}
	// free(string);
	if (ft_strcmp(params->size, ""))
	{
		if (!ft_strcmp(params->size, "hh"))
		{
			if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
			{
				size->hh = (char)number;
				string = ft_itoa_base((size_t)size->hh, base, 0);
				ft_putstr(string);
				ft_putchar('\n');
			}
			else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
				|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
			{
				size->u_hh = (unsigned char)number;
				string = ft_itoa_base((size_t)size->u_hh, base, (params->convers[0] == 'X' ? 1 : 0));
				ft_putstr(string);
				ft_putchar('\n');
			}
		}
		if (!ft_strcmp(params->size, "h"))
		{
			if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
			{
				size->h = (short)number;
				string = ft_itoa_base((size_t)size->h, base, 0);
				ft_putstr(string);
				ft_putchar('\n');
			}
			else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
				|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
			{
				size->u_h = (unsigned short)number;
				string = ft_itoa_base((size_t)size->u_h, base, (params->convers[0] == 'X' ? 1 : 0));
				ft_putstr(string);
				ft_putchar('\n');
			}
		}
		if (!ft_strcmp(params->size, "l"))
		{
			if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
			{
				size->l = (long)number;
				string = ft_itoa_base((size_t)size->l, base, 0);
				ft_putstr(string);
				ft_putchar('\n');
			}
			else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
				|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
			{
				size->u_l = (unsigned long)number;
				string = ft_itoa_base((size_t)size->u_l, base, (params->convers[0] == 'X' ? 1 : 0));
				ft_putstr(string);
				ft_putchar('\n');
			}
		}
		if (!ft_strcmp(params->size, "ll"))
		{
			if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
			{
				size->ll = (long long)number;
				string = ft_itoa_base((size_t)size->ll, base, 0);
				ft_putstr(string);
				ft_putchar('\n');
			}
			else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
				|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
			{
				size->u_ll = (unsigned long long)number;
				string = ft_itoa_base((size_t)size->u_ll, base, (params->convers[0] == 'X' ? 1 : 0));
				ft_putstr(string);
				ft_putchar('\n');
			}
		}
		if (!ft_strcmp(params->size, "j"))
		{
			if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
			{
				size->j = (intmax_t)number;
				string = ft_itoa_base((size_t)size->j, base, 0);
				ft_putstr(string);
				ft_putchar('\n');
			}
			else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
				|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
			{
				size->u_j = (uintmax_t)num;
				string = ft_itoa_base((size_t)size->u_j, base, (params->convers[0] == 'X' ? 1 : 0));
				ft_putstr(string);
				ft_putchar('\n');
			}
		}
		if (!ft_strcmp(params->size, "z"))
		{
			if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
			{
				size->z = (size_t)number;
				string = ft_itoa_base((size_t)size->z, base, 0);
				ft_putstr(string);
				ft_putchar('\n');
			}
			else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
				|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
			{
				size->z = (size_t)number;
				string = ft_itoa_base((size_t)size->z, base, (params->convers[0] == 'X' ? 1 : 0));
				ft_putstr(string);
				ft_putchar('\n');
			}
		}
		free(size);
	}
	// printf("%s", params->out);
	// printf("%i\n", (int)num);
	// if (ft_strcmp(params->precision_char, ""))
	// {
	// 	//while (params->precision > ft_strlen(ft_atoi(())))
	// }
	// if (ft_strcmp(params->width_char, ""))
	// 	printf("lol\n");
	
}

void	ft_converse(t_printf *params, void *string)
{
	params->out = ft_strnew(0);
	// if (params->convers[0] == '%')
	// 	ft_converse_per(params);
	// if (params->convers[0] == 's' || params->convers[0] == 'S')
	// 	ft_converse_string(params, (char *)string);
	if (params->convers[0] == 'i' || params->convers[0] == 'd' || params->convers[0] == 'u' 
		|| params->convers[0] == 'D' || params->convers[0] == 'U' 
		|| params->convers[0] == 'o' || params->convers[0] == 'O' || params->convers[0] == 'x' 
		|| params->convers[0] == 'X' || params->convers[0] == 'p')
		ft_converse_numb(params, string);
	// if (params->converse == 'o' || params->converse == 'O')
	// 	ft_converse_oct(params, string);
	// if (params->converse == 'x' || params->converse == 'X' || params->converse == 'p')
	// 	ft_converse_hex(params, string);
	// if (params->convers[0] == 'c' || params->convers[0] == 'C')
	// 	ft_converse_char(params, (char)string);
}