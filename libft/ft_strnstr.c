/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 21:02:34 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/01 21:02:36 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	f_strcmp(const char *s1, const char *s2, size_t len)
{
	while (*s1 == *s2 && *s1 && len > 0)
	{
		s1++;
		s2++;
		len--;
	}
	if ((*s1) && len == 0)
		return (1);
	if (!(*s1))
	{
		s1--;
		s2--;
	}
	return (*s1 - *s2);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;

	str = (char *)big;
	while (*str && len > 0)
	{
		if (f_strcmp(little, str, len) == 0)
			return (str);
		str++;
		len--;
	}
	if (*little == '\0')
		return (str);
	return (NULL);
}
