/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:52:59 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/03 15:53:00 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*src1;

	str = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (str >= src1 && len > 0)
	{
		str = str + len - 1;
		while (--len > 0)
			*(str--) = src1[len];
		*str = src1[len];
		return (dst);
	}
	else
	{
		while (len-- > 0)
			*(str++) = *(src1++);
		return (dst);
	}
}
