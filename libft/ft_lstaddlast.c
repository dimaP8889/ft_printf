/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlstlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:02:32 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/14 20:02:33 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstaddlast(t_list **lst, t_list *elem)
{
	t_list *new;

	new = *lst;
	if ((*lst) && elem && lst)
	{
		while (new->next)
			new = new->next;
		new->next = elem;
	}
	if (*lst == NULL && elem != NULL && lst != NULL)
		*lst = elem;
}
