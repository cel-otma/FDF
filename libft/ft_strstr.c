/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 22:07:48 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/01 22:08:15 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		if (to_find[j] == '\0')
			return ((char*)str + (i - j + 1));
		i++;
	}
	return (0);
}
