/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:41:06 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/06 21:49:43 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	int		lent;
	char	*dest;

	i = 0;
	lent = 0;
	while (src[lent] != '\0')
	{
		lent++;
	}
	if (!(dest = (char *)malloc(sizeof(char) * (lent + 1))))
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
