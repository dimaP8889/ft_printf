/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 07:23:14 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/01 07:23:17 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && *s1 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if ((*s1 == 0 && n == 0) || n == 0)
	{
		s1--;
		s2--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
