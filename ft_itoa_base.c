/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_size_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:07:37 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/01 18:07:39 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static	size_t		count(size_t index, int base)
{
	size_t		size;

	size = 0;
	while (index > 0)
	{
		size++;
		index = index / base;
	}
	return (size);
}

static	char	*ft_strrev(char *str)
{
	size_t		index;
	char		c;
	size_t		count;

	count = 0;
	index = 0;
	while (str[index])
		index++;
	index--;
	while (index > count)
	{
		c = str[count];
		str[count++] = str[index];
		str[index--] = c;
	}
	return (str);
}

static	char		ft_base(int num, int hex)
{
	char	*base_low;
	char	*base_high;

	base_low = "0123456789abcdef";
	base_high = "0123456789ABCDEF";
	if (hex == 0)
		return (base_low[num]);
	return (base_high[num]);
}

static	char	*mk_str(size_t num, char *str, int base, int hex)
{
	char	*str1;
	int		check;

	str1 = str;
	check = 1;
	while (check >= 0)
	{
		if (num > (size_t)base - 1)
		{
			*(str++) = ft_base(num % base, hex);
			num = num / base;
		}
		else
		{
			*(str++) = ft_base(num % base, hex);
			check = -1;
		}
	}
	*str = '\0';
	return (ft_strrev(str1));
}

char			*ft_itoa_base(size_t index, int base, int hex)
{
	size_t		size;
	char		*str;
	char		*str1;

	size = count(index, base);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str1 = str;
	str = mk_str(index, str, base, hex);
	return (str1);
}