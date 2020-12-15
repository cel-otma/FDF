/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:24:59 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/12 12:13:47 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	cont_size(char const *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	j = ft_strlen(s);
	while ((s[j - 1] == '\n' || s[j - 1] == ' '
				|| s[j - 1] == '\t') && j - 1 >= 0)
		j--;
	while ((s[i] == '\n' || s[i] == ' ' || s[i] == '\t') && s[i])
		i++;
	if (j <= 0)
	{
		j = 1;
		i = 1;
	}
	return (j - i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		m;
	char	*fraiche;

	i = 0;
	m = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] == '\n' || s[i] == ' ' || s[i] == '\t') && s[i])
		i++;
	j = cont_size(s);
	if (!(fraiche = (char *)malloc((j + 1) * sizeof(char))))
		return (0);
	j = j + i;
	while (i < j)
		fraiche[m++] = s[i++];
	fraiche[m] = '\0';
	return (fraiche);
}
