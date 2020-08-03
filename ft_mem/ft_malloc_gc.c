/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquinoa <wquinoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:27:55 by wquinoa           #+#    #+#             */
/*   Updated: 2020/08/03 22:41:17 by wquinoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Collects the allocated pointers into an array.
** Sending 0 into either function frees the array.
*/

void	*ft_malloc_gc(size_t size)
{
	static void *gc_tab[GC_SIZE];
	static int	pos;

	gc_tab[pos] = malloc(size);
	if (!gc_tab[pos] || !size)
	{
		pos = -1;
		while (gc_tab[++pos])
			free(gc_tab[pos]);
		return (NULL);
	}
	return (gc_tab[pos++]);
}

void	*ft_calloc_gc(size_t nbytes, size_t size)
{
	void	*res;
	int		amount;

	amount = nbytes * size;
	res = ft_malloc_gc(amount);
	if (res)
		ft_bzero(&res, amount);
	return (res);
}
