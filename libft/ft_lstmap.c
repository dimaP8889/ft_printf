/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:29:35 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/14 23:29:36 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (lst && new && f)
	{
		new = f(lst);
		lst = lst->next;
		while (lst)
		{
			ft_lstaddlast(&new, f(lst));
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
