/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:48:21 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/07 14:48:22 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static	int				check(char const *s)
{
	char const	*str;

	str = s;
	while (*s)
	{
		if (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		else
			return (0);
	}
	return (1);
}

static	int				countwords(char const *s)
{
	int		index;

	index = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*s)
	{
		while (*s != ' ' && *s != '\n' && *s != '\t' && *s != '\0')
		{
			index++;
			s++;
		}
		if (check(s))
			return (index);
		index++;
		s++;
	}
	return (index);
}

static	char	const	*strsplit(char const *s)
{
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s != '\0')
		s++;
	return (s);
}

char					*ft_strtrim(char const *s)
{
	char *str;
	char *str1;

	if (s)
	{
		str = (char *)malloc(sizeof(char) * (countwords(s) + 1));
		if (str == NULL)
			return (NULL);
		str1 = str;
		s = strsplit(s);
		while (*s)
		{
			while (*s != ' ' && *s != '\n' && *s != '\t' && *s != '\0')
				*(str++) = *(s++);
			if (check(s) || *s == '\0')
			{
				*str = '\0';
				return (str1);
			}
			*(str++) = *(s++);
		}
		*str = '\0';
		return (str1);
	}
	return (0);
}
