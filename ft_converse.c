#include "ft_printf.h"

void	ft_make_flag(t_printf *params, int check_num, char *string)
{
	int		count;
	int		count_zer;
	int		count_sharp;
	int		count_plus;
	int		count_x;
	char	*plus;

	count = 0;
	count_zer = 0;
	count_sharp = 0;
	count_plus = 0;
	count_x = 0;
	while (params->flag[count])
	{
		if (params->flag[count] == '0')
		{
			if (!ft_strcmp(params->precision_char, ""))
			{
				while(params->out[count_zer] == ' ')
				{
					if (check_num == -1)
					{
						params->out[0] = '-';
						count_zer++;
						check_num = 1;
					}
					params->out[count_zer] = '0';
					count_zer++;
				}
			}
		}
		else if (params->flag[count] == ' ')
		{
			if (check_num > 0 && ((int)ft_strlen(string) >= params->width))
				params->out = ft_addletter(params->out, ' ');
		}
		else if (params->flag[count] == '+')
		{
			if (check_num == 1)
			{
				if (ft_strcmp(params->out, ""))
				{
					while (params->out[count_plus + 1])
						count_plus++;
					params->out[count_plus] = '+';
				}
				else
				{
					plus = params->out_num;
					params->out_num = ft_strjoin("+", plus);
					free(plus);
				}
			}
		}
		else if (params->flag[count] == '-')
		{
			params->flag_minus = 1;
		}
		else if (params->flag[count] == '#')
		{
			if (!ft_strcmp(params->convers, "o"))
			{
				if (check_num > 0 && ((int)ft_strlen(string) >= params->precision))
				{
					if (ft_strcmp(params->out, ""))
					{
						while (params->out[count_sharp + 1])
							count_sharp++;
						params->out[count_sharp] = '0';
					}
					else
					{
						plus = params->out_num;
						params->out_num = ft_strjoin("0", plus);
						free(plus);
					}
				}
			}
			else if (!ft_strcmp(params->convers, "x")) //need to correct
			{
				if (check_num > 0 && ((int)ft_strlen(string) >= params->precision))
				{
					while (params->out[count_x])
						count_x++;
					if (count_x > 2)
					{
						plus = params->out_num;
						params->out_num = ft_strjoin("0x", plus);
						free(plus);
					}
					else
					{
						while (params->out[count_sharp + 2])
							count_sharp++;
						params->out[count_sharp] = '0';
						params->out[count_sharp + 1] = 'x';
					}
				}
			}
			else if (!ft_strcmp(params->convers, "X"))//need to correct
			{
				if (check_num > 0 && ((int)ft_strlen(string) >= params->precision))
				{
					while (params->out[count_x])
						count_x++;
					if (count_x > 2)
					{
						plus = params->out_num;
						params->out_num = ft_strjoin("0X", plus);
						free(plus);
					}
					else
					{
						while (params->out[count_sharp + 2])
							count_sharp++;
						params->out[count_sharp] = '0';
						params->out[count_sharp + 1] = 'X';
					}
				}
			}
		}
		count++;
		count_zer = 0;
		count_sharp = 0;
		count_plus = 0;
		count_x = 0;
	}
}
void	ft_make_out(char *string, t_printf *params, int check_num)
{
	int			count_perc;
	int 		count_width;
	int 		length;

	count_width = params->width;
	count_perc = params->precision;
	if (params->width > params->precision && params->precision > (int)ft_strlen(string))
		length = params->width - params->precision;
	if (params->width > params->precision && params->precision <= (int)ft_strlen(string))
		length = params->width - (int)ft_strlen(string);
	if (params->width <= params->precision)
		length = 0;
	length = length - (check_num == 1 ? 0 : 1);
	if (ft_strcmp(params->width_char, ""))
		while (length > 0)
		{
			params->out = ft_addletter(params->out, ' ');
			length--;
		}
	if (check_num == -1)
		params->out_num = ft_addletter(params->out_num, '-');
	if (ft_strcmp(params->precision_char, ""))
		while (count_perc > (int)ft_strlen(string))
		{
			params->out_num = ft_addletter(params->out_num, '0');
			count_perc--;
		}
	ft_make_flag(params, check_num, string);
}

void	ft_converse_numb(t_printf *params, void *number)
{
	int			check_num;
	int			base;
	char 		*string;
	t_size		*size;

	string = NULL;
	size = (t_size *)malloc(sizeof(t_size));
	check_num = 1;
	if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "O"))
		base = 8;
	else if (!ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X") || 
		!ft_strcmp(params->convers, "p"))
		base = 16;
	else
		base = 10;
	if (ft_strcmp(params->size, ""))
	{
		if (!ft_strcmp(params->size, "l") || !ft_strcmp(params->convers, "D") 
			|| !ft_strcmp(params->convers, "U") || !ft_strcmp(params->convers, "O"))
		{
			if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i") || !ft_strcmp(params->convers, "D"))
			{
				size->l = (long)number;
				if (size->l < 0)
				{
					check_num = -1;
					size->l = -size->l;
				}
				string = ft_itoa_base((size_t)size->l, base, 0);
			}
			else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "O")
				|| !ft_strcmp(params->convers, "u") || !ft_strcmp(params->convers, "U")
				|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
			{
				size->u_l = (unsigned long)number;
				string = ft_itoa_base((size_t)size->u_l, base, (params->convers[0] == 'X' ? 1 : 0));
			}
		}
		else if (!ft_strcmp(params->size, "hh"))
		{
			if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
			{
				size->hh = (char)number;
				if (size->hh < 0)
				{
					check_num = -1;
					size->hh = -size->hh;
				}
				string = ft_itoa_base((size_t)size->hh, base, 0);
			}
			else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
				|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
			{
				size->u_hh = (unsigned char)number;
				if (size->u_hh < 0)
				{
					check_num = -1;
					size->u_hh = -size->u_hh;
				}
				string = ft_itoa_base((size_t)size->u_hh, base, (params->convers[0] == 'X' ? 1 : 0));
			}
		}
		else if (!ft_strcmp(params->size, "h"))
		{
			if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
			{
				size->h = (short)number;
				if (size->h < 0)
				{
					check_num = -1;
					size->h = -size->h;
				}
				string = ft_itoa_base((size_t)size->h, base, 0);
			}
			else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
				|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
			{
				size->u_h = (unsigned short)number;
				if (size->u_h < 0)
				{
					check_num = -1;
					size->u_h = -size->u_h;
				}
				string = ft_itoa_base((size_t)size->u_h, base, (params->convers[0] == 'X' ? 1 : 0));
			}
		}
		
		else if (!ft_strcmp(params->size, "ll"))
		{
			if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
			{
				size->ll = (long long)number;
				if (size->ll < 0)
				{
					check_num = -1;
					size->ll = -size->ll;
				}
				string = ft_itoa_base((size_t)size->ll, base, 0);
			}
			else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
				|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
			{
				size->u_ll = (unsigned long long)number;
				string = ft_itoa_base((size_t)size->u_ll, base, (params->convers[0] == 'X' ? 1 : 0));
			}
		}
		else if (!ft_strcmp(params->size, "j"))
		{
			if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
			{
				size->j = (intmax_t)number;
				if (size->j < 0)
				{
					check_num = -1;
					size->j = -size->j;
				}
				string = ft_itoa_base((size_t)size->j, base, 0);
			}
			else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
				|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
			{
				size->u_j = (uintmax_t)number;
				string = ft_itoa_base((size_t)size->u_j, base, (params->convers[0] == 'X' ? 1 : 0));
			}
		}
		else if (!ft_strcmp(params->size, "z"))
		{
			if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i") 
				|| !ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
				|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
			{
				size->z = (size_t)number;
				string = ft_itoa_base((size_t)size->z, base, (params->convers[0] == 'X' ? 1 : 0));
			}
		}
		
	}
	else if (!ft_strcmp(params->convers, "d") || !ft_strcmp(params->convers, "i"))
	{
		size->i = (int)number;
		if (size->i < 0)
		{
			check_num = -1;
			size->i = -size->i;
		}
		string = ft_itoa_base((size_t)size->i, base, 0);
	}
	else if (!ft_strcmp(params->convers, "o") || !ft_strcmp(params->convers, "u")
			|| !ft_strcmp(params->convers, "x") || !ft_strcmp(params->convers, "X"))
	{
		size->u_i = (unsigned int)number;
		string = ft_itoa_base((size_t)size->u_i, base, (params->convers[0] == 'X' ? 1 : 0));
	}
	ft_make_out(string, params, check_num);
	if (params->flag_minus == 1)
	{
		params->out_num = ft_strjoin_free(&params->out_num, string);
		params->out_num = ft_strjoin_free(&params->out_num, params->out);
		ft_putstr(params->out_num);
	}
	else
	{
		params->out = ft_strjoin_free(&params->out, params->out_num);
		params->out = ft_strjoin_free(&params->out, string);
		ft_putstr(params->out);
	}
	ft_putchar('\n');
	free(string);
	free(size);	
}

void	ft_converse(t_printf *params, void *string)
{
	params->out = ft_strnew(0);
	params->out_num = ft_strnew(0);
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