/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 06:03:30 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/01 06:03:30 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		index;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (str == NULL)
		return (NULL);
	index = -1;
	while (s1[++index])
		str[index] = s1[index];
	str[index] = '\0';
	return (str);
}
