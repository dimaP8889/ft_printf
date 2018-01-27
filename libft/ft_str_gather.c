/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_gather.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:10:50 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/15 13:10:52 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static	int		count(const char **s)
{
	int		count;

	count = 0;
	while (*s)
	{
		count = ft_strlen(*s) + count;
		count++;
		s++;
	}
	return (count);
}

char			*ft_str_gather(char const **s, char c)
{
	char	*str;
	char	*str1;
	int		index;

	index = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (count(s) + 1));
	if (!str)
		return (0);
	str1 = str;
	while (*s)
	{
		while ((*s)[index])
			*(str++) = (*s)[index++];
		s++;
		index = 0;
		if (*s)
			*(str++) = c;
		else
			*str = 0;
	}
	return (str1);
}
