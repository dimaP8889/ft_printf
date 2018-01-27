/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:27:27 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/03 17:27:28 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	*src1;

	str = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (len-- > 0)
	{
		*str = *src1;
		if (*src1 == (unsigned char)c)
		{
			str++;
			return (str);
		}
		str++;
		src1++;
	}
	return (NULL);
}
