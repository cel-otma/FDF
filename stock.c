/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:51:49 by cel-otma          #+#    #+#             */
/*   Updated: 2019/12/06 17:32:27 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, t_dess *dess)
{
	int x_;
	int y_;

	x_ = *x;
	y_ = *y;
	*x = (x_ - y_) * cos(dess->angle);
	*y = (x_ + y_) * sin(dess->angle);
}

void	restock_tab(t_dess *dess)
{
	int i;
	int j;

	i = 0;
	while (i < dess->nb_ligne)
	{
		j = 0;
		while (j < dess->nb_colone)
		{
			dess->tableau[i].z[j] = dess->tableau[i].tab[j] * dess->heigth;
			dess->tableau[i].x[j] = (j * dess->zoom) + dess->position_x;
			dess->tableau[i].y[j] = (i * dess->zoom) + dess->position_y;
			if (dess->view == 1)
				iso(&dess->tableau[i].x[j], &dess->tableau[i].y[j], dess);
			j++;
		}
		i++;
	}
}

void	remplir(int j, t_dess *dess, char *line)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
	{
		dess->tableau[j].z[i] = ft_atoi(tab[i]) * dess->heigth;
		dess->tableau[j].tab[i] = ft_atoi(tab[i]) * dess->heigth;
		dess->tableau[j].x[i] = (i * dess->zoom) + dess->position_x;
		dess->tableau[j].y[i] = (j * dess->zoom) + dess->position_y;
		if (dess->view == 1)
			iso(&dess->tableau[j].x[i], &dess->tableau[j].y[i], dess);
		i++;
	}
	freesplit(tab, line);
}

void	stock_in(char *ch, t_dess *dess)
{
	char	*line;
	int		fd;
	int		j;

	fd = open(ch, O_RDONLY);
	j = 0;
	dess->tableau = (t_t*)malloc(sizeof(t_t) * dess->nb_ligne);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(dess->tableau[j].x = (int *)malloc(sizeof(int)
						* dess->nb_colone)))
			exit(0);
		if (!(dess->tableau[j].y = (int *)malloc(sizeof(int)
						* dess->nb_colone)))
			exit(0);
		if (!(dess->tableau[j].z = (int *)malloc(sizeof(int)
						* dess->nb_colone)))
			exit(0);
		if (!(dess->tableau[j].tab = (int *)malloc(sizeof(int)
						* dess->nb_colone)))
			exit(0);
		remplir(j, dess, line);
		j++;
	}
	close(fd);
}
