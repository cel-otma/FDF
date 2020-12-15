/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 23:11:44 by cel-otma          #+#    #+#             */
/*   Updated: 2019/04/02 00:45:30 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strcmp(const char *src1, const char *src2)
{
	int i;

	i = 0;
	while (src1[i] != '\0' && src2[i] != '\0' && src1[i] == src2[i])
		i++;
	return (((unsigned char *)src1)[i] - ((unsigned char *)src2)[i]);
}
