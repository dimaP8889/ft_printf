/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:12:28 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/02 17:12:29 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	char	*str1;

	str = (char *)b;
	str1 = str;
	while (len-- > 0)
		*(str++) = c;
	return (str1);
}
