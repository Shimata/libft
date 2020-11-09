/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquinoa <wquinoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:39:49 by wquinoa           #+#    #+#             */
/*   Updated: 2020/11/09 10:58:04 by wquinoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*find_first_of(char const *str, char const *set)
{
	if (!str)
		return (NULL);
	while (*str && !ft_strchr(set, *str))
		str++;
	return (*str ? (char*)str : NULL);
}

char		*skip_symbols(char const *str, char const *set)
{
	if (!str)
		return (NULL);
	while (*str && ft_strchr(set, *str))
		str++;
	return (*str ? (char*)str : NULL);
}

static int	num_blocks(char const *str, char const *set)
{
	int count;

	count = 0;
	while (str)
	{
		str = find_first_of(str, set);
		count++;
		str = skip_symbols(str, set);
	}
	return (count);
}

char		**ft_strtok(char const *str, char const *set)
{
	char	**result;
	char	**head;
	char	*word_end;

	str = skip_symbols(str, set);
	result = malloc(sizeof(char *) * num_blocks(str, set) + 1);
	if ((head = result))
	{
		while (str)
		{
			word_end = find_first_of(str, set);
			if (!(*result++ = ft_substr(str, 0, word_end - str)))
				return (ft_tabclear(head));
			str = skip_symbols(word_end, set);
		}
		*result = NULL;
	}
	return (head);
}
