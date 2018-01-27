/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:28:23 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/16 01:28:23 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_preorder(t_btree *tree, void (*f)(void *))
{
	if (!tree || !f)
		return ;
	f(tree->data);
	if (tree->left)
		ft_preorder(tree->left, f);
	if (tree->right)
		ft_preorder(tree->right, f);
}
