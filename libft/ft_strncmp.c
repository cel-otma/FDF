/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:46:00 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/09 10:32:47 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_strncmp(const char *src1, const char *src2, size_t l)
{
	size_t				i;
	unsigned char		*sr1;
	unsigned char		*sr2;

	i = 0;
	sr1 = (unsigned char*)src1;
	sr2 = (unsigned char*)src2;
	while ((sr1[i] || sr2[i]) && i < l)
	{
		if (sr1[i] != sr2[i])
			return (sr1[i] - sr2[i]);
		i++;
	}
	return (0);
}
