/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:46:22 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/04 14:46:22 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char *str;
	char *str1;

	str = (char *)malloc(size);
	str1 = str;
	if (str == NULL)
		return (NULL);
	while (size-- > 0)
		*(str++) = 0;
	return (str1);
}
