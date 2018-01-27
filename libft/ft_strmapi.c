/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:27:19 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/07 13:27:19 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		c;
	char				*str;
	char				*str1;
	unsigned int		a;

	a = 0;
	if (s && f)
	{
		c = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * (c + 1));
		if (str == NULL)
			return (NULL);
		str1 = str;
		while (*s)
			*(str++) = f(a++, *(s++));
		*str = '\0';
		return (str1);
	}
	return (NULL);
}
