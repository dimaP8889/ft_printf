/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:16:38 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/05 21:16:39 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		c;
	char	*str;
	char	*str1;

	if (s && f)
	{
		c = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * (c + 1));
		if (str == NULL)
			return (NULL);
		str1 = str;
		while (*s)
			*(str++) = f(*(s++));
		*str = '\0';
		return (str1);
	}
	return (NULL);
}
