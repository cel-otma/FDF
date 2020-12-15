/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 22:20:14 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/01 23:03:33 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t t)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (char*)(str);
	while (str[i] != '\0' && i < t)
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
