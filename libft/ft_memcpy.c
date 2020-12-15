/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:51:49 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/01 01:12:47 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*s;
	char	*d;

	i = 0;
	s = (char*)src;
	d = (char*)dst;
	while (i < (int)n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
