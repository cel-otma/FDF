/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 20:21:07 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/01 11:28:40 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	s = (char*)src;
	d = (char*)dst;
	while (i < n)
	{
		if (s[i] != (char)c)
			d[i] = s[i];
		else
		{
			d[i] = s[i];
			return (&d[i + 1]);
		}
		i++;
	}
	return (0);
}
