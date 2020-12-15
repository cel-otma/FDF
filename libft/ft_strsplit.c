/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:36:45 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/21 19:11:52 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		nombre_mot(char const *s, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				nb++;
			}
			i++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (nb);
}

static	int		n(char const *s, int i, char c)
{
	int j;

	j = 0;
	while (s[i + j])
	{
		if (s[i + j + 1] == c)
		{
			j++;
			return (j);
		}
		j++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	int		m;
	char	**ch;

	i = -1;
	k = 0;
	if (s == NULL)
		return (NULL);
	if (!(ch = (char **)malloc((nombre_mot(s, c) + 1) * sizeof(char*))))
		return (NULL);
	while (s[++i])
		if (s[i] != c)
		{
			m = 0;
			if (!(ch[k] = (char *)malloc((n(s, i, c) + 1) * sizeof(char))))
				return (NULL);
			while (m < n(s, (i - m), c))
				ch[k][m++] = s[i++];
			ch[k++][m++] = '\0';
			if (s[i] == '\0')
				break ;
		}
	ch[k] = 0;
	return (ch);
}
