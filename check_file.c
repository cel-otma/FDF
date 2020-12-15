/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:55:32 by cel-otma          #+#    #+#             */
/*   Updated: 2019/12/04 14:34:35 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_fd(int fd, char *str)
{
	if (fd < 0)
	{
		ft_putstr("no file ");
		ft_putendl(str);
		exit(1);
	}
}

int		count_mot(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	freesplit(char **tab, char *line)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	free(line);
}

void	check_error(char **tab, char *line, int error)
{
	if (error == 1)
	{
		ft_putendl("Error : line length!");
		freesplit(tab, line);
		exit(1);
	}
	else
	{
		ft_putendl("No data found.");
		exit(1);
	}
}

void	check_file(char *str, t_dess *dess)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(str, O_RDONLY);
	check_fd(fd, str);
	while (get_next_line(fd, &line) != 0)
	{
		if ((tab = ft_strsplit(line, ' ')) == NULL)
			exit(1);
		if (dess->nb_colone == -1)
			if ((dess->nb_colone = count_mot(tab)) == 0)
			{
				ft_putendl("No data found");
				exit(1);
			}
		if (dess->nb_colone > count_mot(tab))
			check_error(tab, line, 1);
		dess->nb_ligne++;
	}
	if (dess->nb_colone == -1)
		check_error(tab, line, 2);
	freesplit(tab, line);
	close(fd);
}
