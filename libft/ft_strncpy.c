/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 06:29:13 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/01 06:29:15 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	index;

	index = 0;
	while (src[index] && len > 0)
	{
		dst[index] = src[index];
		index++;
		len--;
	}
	while (len > 0)
	{
		dst[index] = '\0';
		len--;
		index++;
	}
	return (dst);
}
