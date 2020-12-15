/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:46:53 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/09 21:58:09 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nb1;

	nb1 = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb1 = n * (-1);
	}
	if (nb1 > 9)
	{
		ft_putnbr_fd(nb1 / 10, fd);
		ft_putnbr_fd(nb1 % 10, fd);
	}
	else
	{
		ft_putchar_fd(nb1 + '0', fd);
	}
}
