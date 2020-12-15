/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:37:26 by cel-otma          #+#    #+#             */
/*   Updated: 2019/07/03 01:03:19 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line(char **tab, char **line, int fd)
{
	int		i;
	char	*temp;

	i = 0;
	while (tab[fd][i] && tab[fd][i] != '\n')
		i++;
	if (!(*line = ft_strsub(tab[fd], 0, i)))
		return (-1);
	if (tab[fd][i] == '\n')
	{
		temp = tab[fd];
		if (!(tab[fd] = ft_strdup(tab[fd] + i + 1)))
			return (-1);
		free(temp);
	}
	else
		tab[fd] = NULL;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			size;
	static char *tab[4864];
	char		*temp;

	if (fd < 0 || fd > 4864 || read(fd, buf, 0) < 0)
		return (-1);
	if (!tab[fd])
		if (!(tab[fd] = ft_strnew(0)))
			return (-1);
	while (!ft_strchr(tab[fd], '\n') && (size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		temp = tab[fd];
		if (!(tab[fd] = ft_strjoin(tab[fd], buf)))
			return (-1);
		free(temp);
	}
	if (tab[fd][0] == '\0' && size < 1)
		return (size);
	return (get_line(tab, line, fd));
}
