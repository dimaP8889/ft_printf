/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inoder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:16:53 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/16 01:16:54 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_inoder(t_btree *tree, void (*f)(void *))
{
	if (!tree || !f)
		return ;
	if (tree->left)
		ft_inoder(tree->left, f);
	f(tree->data);
	if (tree->right)
		ft_inoder(tree->right, f);
}
