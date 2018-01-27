/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsortcontent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:04:14 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/15 16:04:14 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static	int		count(t_list *list)
{
	int c;

	c = 0;
	while (list)
	{
		c++;
		list = list->next;
	}
	return (c);
}

static	t_list	*bubblesort(int num, t_list *list)
{
	t_list	*check;
	t_list	*list1;
	t_list	*list2;

	check = (t_list *)malloc(sizeof(t_list));
	list1 = list;
	list2 = list;
	while (num)
	{
		while (list->next)
		{
			if (ft_strcmp((char *)list->content,
				(char *)list->next->content) > 0)
			{
				check->content = list->content;
				list->content = list->next->content;
				list->next->content = check->content;
			}
			list = list->next;
		}
		num--;
		list = list1;
	}
	return (list2);
}

t_list			*ft_lstsortcontent(t_list *list)
{
	t_list	*list1;
	int		num;

	if (!list)
		return (0);
	num = count(list);
	list1 = bubblesort(num, list);
	return (list1);
}
