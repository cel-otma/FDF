/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:32:21 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/12 17:13:06 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fraiche;
	int		lent;

	i = 0;
	if (s == NULL)
		return (NULL);
	lent = ft_strlen(s);
	if (!(fraiche = (char*)malloc(sizeof(char) * (lent + 1))))
		return (NULL);
	if (fraiche == NULL)
		return (0);
	while (s[i])
	{
		fraiche[i] = f(s[i]);
		i++;
	}
	fraiche[i] = '\0';
	return (fraiche);
}
