/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:28:07 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/03 18:00:53 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;
	char	*sr1;
	char	*sr2;

	i = 0;
	sr1 = (char*)str1;
	sr2 = (char *)str2;
	while (i < n)
	{
		if (((unsigned char *)sr1)[i] != ((unsigned char *)sr2)[i])
			return (((unsigned char *)sr1)[i] - ((unsigned char *)sr2)[i]);
		i++;
	}
	return (0);
}
