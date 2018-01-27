/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:01:33 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/07 14:01:33 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *str1;

	if (s1 && s2)
	{
		str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (str == NULL)
			return (NULL);
		str1 = str;
		str = ft_strcpy(str, (char *)s1);
		str = ft_strcat(str, (char *)s2);
		return (str);
	}
	return (0);
}
