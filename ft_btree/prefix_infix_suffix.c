/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_infix_suffix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquinoa <wquinoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 12:48:47 by wquinoa           #+#    #+#             */
/*   Updated: 2020/08/03 22:42:22 by wquinoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	tree_apply_prefix(t_btree *root, void (*af)(void *))
{
	if (!root)
		return ;
	af(root);
	tree_apply_prefix(root->left, af);
	tree_apply_prefix(root->right, af);
}

void	tree_apply_infix(t_btree *root, void (*af)(void *))
{
	if (!root)
		return ;
	tree_apply_infix(root->left, af);
	af(root);
	tree_apply_infix(root->right, af);
}

void	tree_apply_suffix(t_btree *root, void (*af)(void *))
{
	if (!root)
		return ;
	tree_apply_suffix(root->left, af);
	tree_apply_suffix(root->right, af);
	af(root);
}
