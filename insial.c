/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insial.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:36:50 by cel-otma          #+#    #+#             */
/*   Updated: 2019/12/06 17:34:19 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	insial_x(t_dess *dess, int i, int j)
{
	if (dess->tableau[j].tab[i] - dess->tableau[j].tab[i + 1] != 0)
		dess->color = 0x542165;
	else if (dess->tableau[j].tab[i] != 0 && dess->tableau[j].tab[i]
			- dess->tableau[j].tab[i + 1] == 0)
		dess->color = 0xfd32aa;
	dess->x0 = dess->tableau[j].z[i] + dess->tableau[j].x[i];
	dess->x1 = dess->tableau[j].z[i + 1] + dess->tableau[j].x[i + 1];
	dess->y0 = dess->tableau[j].z[i] + dess->tableau[j].y[i];
	dess->y1 = dess->tableau[j].z[i + 1] + dess->tableau[j].y[i + 1];
	dess->dx = abs(dess->x1 - dess->x0);
	dess->dy = abs(dess->y1 - dess->y0);
	dess->sx = (dess->x0 > dess->x1) ? -1 : 1;
	dess->sy = (dess->y0 > dess->y1) ? -1 : 1;
}

void	insial_y(t_dess *dess, int i, int j)
{
	if (dess->tableau[j].tab[i] - dess->tableau[j + 1].tab[i] != 0)
		dess->color = 0x542165;
	else if (dess->tableau[j].tab[i] != 0 && dess->tableau[j].tab[i]
			- dess->tableau[j + 1].tab[i] == 0)
		dess->color = 0xfd32aa;
	dess->x0 = dess->tableau[j].z[i] + dess->tableau[j].x[i];
	dess->x1 = dess->tableau[j + 1].z[i] + dess->tableau[j + 1].x[i];
	dess->y0 = dess->tableau[j].z[i] + dess->tableau[j].y[i];
	dess->y1 = dess->tableau[j + 1].z[i] + dess->tableau[j + 1].y[i];
	dess->dx = abs(dess->x1 - dess->x0);
	dess->dy = abs(dess->y1 - dess->y0);
	dess->sx = (dess->x0 > dess->x1) ? -1 : 1;
	dess->sy = (dess->y0 > dess->y1) ? -1 : 1;
}

void	fre_dess(t_dess *dess)
{
	int i;

	i = 0;
	while (dess->nb_ligne > i)
	{
		(dess->tableau[i].x) ? free(dess->tableau[i].x) : 0;
		(dess->tableau[i].y) ? free(dess->tableau[i].y) : 0;
		(dess->tableau[i].z) ? free(dess->tableau[i].z) : 0;
		(dess->tableau[i].tab) ? free(dess->tableau[i].tab) : 0;
		i++;
	}
	mlx_destroy_window(dess->ptr, dess->win);
	(dess->tableau) ? free(dess->tableau) : 0;
}
