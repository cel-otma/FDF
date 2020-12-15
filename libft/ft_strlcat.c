/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:17:18 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/03 22:16:59 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		lentd;
	size_t		i;
	size_t		j;

	lentd = 0;
	i = 0;
	while (dest[lentd] != '\0')
		lentd++;
	while (src[i] != '\0')
		i++;
	j = (lentd < size ? lentd : size) + i;
	if (size == 0)
		return (i);
	i = 0;
	while (src[i] != '\0' && lentd < size - 1)
	{
		dest[lentd] = src[i];
		lentd++;
		i++;
	}
	dest[lentd] = '\0';
	return (j);
}
