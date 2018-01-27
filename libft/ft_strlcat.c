/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 07:10:15 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/01 07:10:16 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t len)
{
	size_t		index;
	size_t		count;
	size_t		del;

	del = len;
	count = ft_strlen(s1);
	index = ft_strlen(s2);
	while (*s1)
	{
		if (del > 0)
			del--;
		s1++;
	}
	while (*s2 && del-- > 1)
		*(s1++) = *(s2++);
	*s1 = '\0';
	if (count > len)
		return (index + len);
	else
		return (count + index);
}
