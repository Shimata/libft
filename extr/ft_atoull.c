/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquinoa <wquinoa@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 19:53:08 by wquinoa           #+#    #+#             */
/*   Updated: 2020/11/14 05:21:53 by wquinoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atoull(const char *str)
{
	const unsigned long long	limit = UINT64_MAX / 10;
	unsigned long long			res;
	int							i;
	
	res = 0;
	i = 0;
	while (*str && ft_isspace(*str))
		str++;
	while (ft_isdigit(str[i]))
		i++;
	while (--i >= 0)
	{
		if (res > limit && i > 0)
			return (0);
		res *= 10;
		res += (str[i] - '0');
	}
	return (res);
}
