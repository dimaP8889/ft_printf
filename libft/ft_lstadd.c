/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:28:03 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/14 23:28:04 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (!(*alst))
	{
		new->next = NULL;
		*alst = new;
		return ;
	}
	new->next = *alst;
	*alst = new;
}
