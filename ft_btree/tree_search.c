/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquinoa <wquinoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:14:38 by wquinoa           #+#    #+#             */
/*   Updated: 2020/08/03 22:43:25 by wquinoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_btree	*tree_search(t_btree *root, void *item, int (*cmp)(void *, void *))
{
	if (!root)
		return (NULL);
	tree_search(root->left, item, cmp);
	if (!cmp(root->item, item))
		return (root->item);
	tree_search(root->right, item, cmp);
	return (NULL);
}
