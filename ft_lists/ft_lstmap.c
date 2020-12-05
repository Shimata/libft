/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquinoa <wquinoa@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 06:20:19 by wquinoa           #+#    #+#             */
/*   Updated: 2020/12/05 15:27:25 by sbashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*next_elem;
	void	*tmp;

	if (!lst)
		return (NULL);
	tmp = f(lst->content);
	if (!(new = ft_lstnew(tmp)))
	{
		del(tmp);
		return (NULL);
	}
	next_elem = new;
	while ((lst = lst->next))
	{
		tmp = f(lst->content);
		if (!(next_elem->next = ft_lstnew(tmp)))
		{
			del(tmp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		next_elem = next_elem->next;
	}
	return (new);
}
