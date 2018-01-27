/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 22:27:59 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/03 22:28:00 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
		while (*s)
			ft_putchar_fd(*(s++), fd);
	else
		return ;
}
