/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:59:35 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/12 17:13:23 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*fraiche;
	int		lens1;
	int		lens2;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(fraiche = (char *)malloc((sizeof(char) * (lens1 + lens2) + 1))))
		return (0);
	ft_strcpy(fraiche, (char *)s1);
	ft_strcat(fraiche, (char *)s2);
	return (fraiche);
}
