/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:46:59 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/19 18:12:41 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t lent)
{
	char	*dst1;
	char	*src1;

	dst1 = (char *)dst;
	src1 = (char *)src;
	if (dst1 > src1)
	{
		while (lent > 0)
		{
			lent--;
			dst1[lent] = src1[lent];
		}
	}
	else
		ft_memcpy(dst1, src1, lent);
	return (dst);
}
