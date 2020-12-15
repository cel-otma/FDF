/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:46:43 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/19 15:12:41 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	str = malloc(sizeof(void) * size);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, size);
	return (str);
}
