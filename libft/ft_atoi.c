/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:26:15 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/14 23:26:17 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		split(char c)
{
	if (c == '\n' || c == ' ' || c == '\t'
		|| c == '\r' || c == '\f'
		|| c == '\v')
		return (1);
	return (0);
}

static	int		result(unsigned char *str, int is_neg)
{
	unsigned long int		res;

	res = 0;
	while (*str <= '9' && *str >= '0' && *str)
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
		&& (*str - '0') > 7)) && is_neg == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
		&& (*str - '0') > 8)) && is_neg == -1)
			return (0);
		res = (*(str++) - '0') + res * 10;
	}
	return (is_neg * res);
}

int				ft_atoi(const char *str1)
{
	unsigned char					*str;
	int								is_neg;
	int								res;

	res = 0;
	str = (unsigned char *)str1;
	is_neg = 1;
	while (split(*str))
		str++;
	if (*str == '-' && is_neg == 1)
	{
		is_neg = -1;
		str++;
	}
	if (*str == '+' && is_neg == 1)
		str++;
	res = result(str, is_neg);
	return (res);
}
