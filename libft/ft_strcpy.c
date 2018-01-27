/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 06:17:16 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/01 06:17:17 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	index;

	index = -1;
	while (src[++index])
		dst[index] = src[index];
	dst[index] = '\0';
	return (dst);
}
