/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:37:11 by cel-otma          #+#    #+#             */
/*   Updated: 2019/12/04 11:17:31 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <libc.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

typedef struct	s_t{
	int *x;
	int	*y;
	int	*z;
	int	*tab;
}				t_t;

typedef struct	s_dess{
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	void	*ptr;
	void	*win;
	int		zoom;
	double	angle;
	int		position_x;
	int		position_y;
	int		nb_colone;
	double	heigth;
	int		view;
	int		color;
	int		nb_ligne;
	t_t		*tableau;
}				t_dess;

void			check_file(char *str, t_dess *dess);
void			conter(t_dess *dess);
void			stock_in(char *ch, t_dess *dess);
void			freesplit(char **tab, char *line);
void			restock_tab(t_dess *dess);
void			menu(t_dess dess);
void			insial_x(t_dess *dess, int i, int j);
void			insial_y(t_dess *dess, int i, int j);
void			fre_dess(t_dess *dess);
#endif
