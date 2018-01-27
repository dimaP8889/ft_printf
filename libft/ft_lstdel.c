/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:29:01 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/14 23:29:02 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;

	new = *alst;
	if (!alst || !del || !(*alst))
		return ;
	while (new)
	{
		del((new)->content, (new)->content_size);
		free(new);
		new = new->next;
	}
	*alst = NULL;
}
