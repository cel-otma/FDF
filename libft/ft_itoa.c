/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:01:05 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/20 14:26:05 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_remplir(char *tab, unsigned int nb, int s)
{
	while (nb > 9)
	{
		tab[s] = nb % 10 + '0';
		s--;
		nb = nb / 10;
	}
	tab[s] = nb + '0';
}

char			*ft_itoa(int n)
{
	char			*tab;
	unsigned int	nbr;
	int				size;

	size = 0;
	if (n < 0)
	{
		n = -n;
		size = 1;
	}
	nbr = n;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		size++;
	}
	size++;
	if (!(tab = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	tab[size--] = '\0';
	tab[0] = '-';
	nbr = n;
	ft_remplir(tab, nbr, size);
	return (tab);
}
