/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:31:46 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/14 23:31:47 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static	int		count(int index)
{
	int		size;

	size = 0;
	if (index <= 0)
	{
		index = -index;
		size++;
	}
	while (index > 0)
	{
		size++;
		index = index / 10;
	}
	return (size);
}

static	char	*ft_strrev(char *str)
{
	int		index;
	char	c;
	int		count;

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

static	char	*mk_str(int num, char *str)
{
	char *str1;

	str1 = str;
	while (num >= 0)
	{
		if (num > 9)
		{
			*(str++) = num % 10 + '0';
			num = num / 10;
		}
		else
		{
			*(str++) = num % 10 + '0';
			num = -1;
		}
	}
	*str = '\0';
	return (ft_strrev(str1));
}

char			*ft_itoa(int index)
{
	int		size;
	char	*str;
	char	*str1;

	size = count(index);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str1 = str;
	if (index == -2147483648)
	{
		*(str++) = '-';
		*(str++) = '2';
		index = 147483648;
	}
	if (index < 0)
	{
		*(str++) = '-';
		index = -index;
	}
	str = mk_str(index, str);
	return (str1);
}
