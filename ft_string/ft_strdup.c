/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquinoa <wquinoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:24:43 by wquinoa           #+#    #+#             */
/*   Updated: 2020/11/09 11:03:46 by wquinoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	char	*d;

	if (!(dst = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	d = dst;
	while (*s)
		*(dst++) = *(s++);
	*dst = '\0';
	return (d);
}
