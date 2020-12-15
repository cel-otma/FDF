/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:37:48 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/03 15:15:28 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (d[i] == (unsigned char)c)
			return (d + i);
		else
			i++;
	}
	return (0);
}
