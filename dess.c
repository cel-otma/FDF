/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dess.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:15:13 by cel-otma          #+#    #+#             */
/*   Updated: 2019/12/06 17:31:06 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_x(t_dess *dess)
{
	int i;

	i = 0;
	while (1)
	{
		if (dess->x0 == dess->x1 && dess->y0 == dess->y1)
			break ;
		mlx_pixel_put(dess->ptr, dess->win, dess->x0, dess->y0, dess->color);
		dess->x0 += dess->sx;
		dess->err += dess->dy;
		if (dess->err >= dess->dx)
		{
			dess->err -= dess->dx;
			dess->y0 += dess->sy;
		}
	}
}

void		draw_y(t_dess *dess)
{
	int i;

	i = 0;
	while (1)
	{
		if (dess->x0 == dess->x1 && dess->y0 == dess->y1)
			break ;
		mlx_pixel_put(dess->ptr, dess->win, dess->x0, dess->y0, dess->color);
		dess->y0 += dess->sy;
		dess->err += dess->dx;
		if (dess->err >= dess->dy)
		{
			dess->err -= dess->dy;
			dess->x0 += dess->sx;
		}
	}
}

void		bresenham_x(int i, int j, t_dess *dess)
{
	while (j < dess->nb_ligne)
	{
		i = 0;
		while (i + 1 < dess->nb_colone)
		{
			dess->color = 0xfffff;
			insial_x(dess, i, j);
			if (dess->dx > dess->dy)
			{
				dess->err = dess->dx / 2;
				draw_x(dess);
			}
			else
			{
				dess->err = dess->dy / 2;
				draw_y(dess);
			}
			i++;
		}
		j++;
	}
}

void		bresenham_y(int i, int j, t_dess *dess)
{
	while (j + 1 < dess->nb_ligne)
	{
		i = 0;
		while (i < dess->nb_colone)
		{
			dess->color = 0xfffff;
			insial_y(dess, i, j);
			if (dess->dx > dess->dy)
			{
				dess->err = dess->dx / 2;
				draw_x(dess);
			}
			else
			{
				dess->err = dess->dy / 2;
				draw_y(dess);
			}
			i++;
		}
		j++;
	}
}

void		conter(t_dess *dess)
{
	int i;
	int j;

	i = 0;
	j = 0;
	mlx_clear_window(dess->ptr, dess->win);
	menu(*dess);
	bresenham_x(i, j, dess);
	j = 0;
	i = 0;
	bresenham_y(i, j, dess);
}
