/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 06:45:14 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/01 06:45:14 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int				index;
	char			*str;

	str = s1;
	index = 0;
	while (*s1)
		s1++;
	while (*s2 && n-- > 0)
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (str);
}
