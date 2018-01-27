/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 05:46:53 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/01 05:46:54 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t		ft_strlen(const char *s)
{
	size_t index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}
