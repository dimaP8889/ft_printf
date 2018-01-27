/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:04:59 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/01 19:05:00 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		f_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	if (!(*s1))
	{
		s1--;
		s2--;
	}
	return (*s1 - *s2);
}

char			*ft_strstr(const char *big, const char *little)
{
	char	*str;

	str = (char *)big;
	while (*str)
	{
		if (f_strcmp(little, str) == 0)
			return (str);
		str++;
	}
	if (*little == '\0')
		return (str);
	return (NULL);
}
