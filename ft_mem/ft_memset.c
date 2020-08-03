/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquinoa <wquinoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:18:27 by wquinoa           #+#    #+#             */
/*   Updated: 2020/08/03 21:54:10 by wquinoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	fill_lword(unsigned long n)
{
	unsigned long	word;
	int				size;

	word = 0;
	size = sizeof(long);
	while (size-- >= 0)
		word |= (n << (size * (sizeof(char))));
	return (word);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*byte;
	unsigned long	*word;
	unsigned long	block;
	const int		size = sizeof(unsigned long);

	byte = (unsigned char*)b;
	block = 0;
	while (len % size)
	{
		*(byte++) = (unsigned char)c;
		len--;
	}
	if (len)
	{
		word = (unsigned long *)byte;
		block = fill_lword(c);
		while (len > 0)
		{
			*(word++) = block;
			len -= size;
		}
	}
	return (b);
}
