/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:29:21 by cel-otma          #+#    #+#             */
/*   Updated: 2019/12/04 14:31:36 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_dess dess)
{
	mlx_string_put(dess.ptr, dess.win, 10,
			10, 0x2df900, "Change heigth : x / z");
	mlx_string_put(dess.ptr, dess.win, 10,
			40, 0x2df900, "change position : arrow");
	mlx_string_put(dess.ptr, dess.win, 10,
			70, 0x2df900, "Zoom : + / -");
	mlx_string_put(dess.ptr, dess.win, 10,
			100, 0x2df900, "iso : i");
	mlx_string_put(dess.ptr, dess.win, 10,
			130, 0x2df900, "paral : p");
	mlx_string_put(dess.ptr, dess.win, 10,
			160, 0x2df900, "Change angle : s / a");
	mlx_string_put(dess.ptr, dess.win, 10,
			190, 0x2df900, "Exit : Esc");
}

int		key_press_cont(int keycode, t_dess *dess)
{
	if (keycode == 69)
		dess->zoom += 5;
	else if (keycode == 78)
		dess->zoom -= 5;
	else if (keycode == 34)
	{
		dess->view = 1;
		dess->heigth = 1;
	}
	else if (keycode == 35)
	{
		dess->view = 0;
		dess->heigth = 0;
	}
	else if (keycode == 0)
		dess->angle += 0.0015;
	else if (keycode == 1)
		dess->angle -= 0.0015;
	return (1);
}

int		key_press(int keycode, t_dess *dess)
{
	if (keycode == 53)
	{
		fre_dess(dess);
		exit(0);
	}
	if (keycode == 124)
		dess->position_x += 20;
	else if (keycode == 123)
		dess->position_x -= 20;
	else if (keycode == 125)
		dess->position_y += 20;
	else if (keycode == 126)
		dess->position_y -= 20;
	else if (keycode == 7 && dess->view == 1)
		dess->heigth += 10;
	else if (keycode == 6 && dess->view == 1)
		dess->heigth -= 10;
	key_press_cont(keycode, dess);
	restock_tab(dess);
	conter(dess);
	return (1);
}

int		main(int argc, char **argv)
{
	t_dess dess;

	if (argc != 2)
	{
		write(1, "usage : ./fdf <filename>\n", 25);
		return (0);
	}
	dess.ptr = mlx_init();
	dess.win = mlx_new_window(dess.ptr, 1500, 2000, "FdF");
	dess.nb_colone = -1;
	dess.nb_ligne = 0;
	dess.position_x = 800;
	dess.position_y = 100;
	dess.view = 1;
	dess.zoom = 30;
	dess.heigth = 1;
	dess.angle = 0.523599;
	check_file(argv[1], &dess);
	stock_in(argv[1], &dess);
	conter(&dess);
	mlx_hook(dess.win, 2, 0, key_press, &dess);
	mlx_loop(dess.ptr);
	return (0);
}
