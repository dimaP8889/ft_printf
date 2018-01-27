/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:49:46 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/07 13:49:47 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*str1;

	if (s)
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		str1 = str;
		if (str == NULL)
			return (NULL);
		while (s[start] && len-- > 0)
			*(str++) = s[start++];
		*str = '\0';
		return (str1);
	}
	return (0);
}
