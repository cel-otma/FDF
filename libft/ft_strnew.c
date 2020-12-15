/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:58:29 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/20 15:11:10 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*fraiche;
	size_t	i;

	i = 0;
	if (!(fraiche = (char *)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		fraiche[i] = '\0';
		i++;
	}
	fraiche[i] = '\0';
	return (fraiche);
}
