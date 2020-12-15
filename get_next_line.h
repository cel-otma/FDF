/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:55:48 by cel-otma          #+#    #+#             */
/*   Updated: 2019/07/05 15:15:30 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#include "libft/libft.h"
#include <libc.h>
#define BUFF_SIZE 32

int		get_next_line(const int fd, char **line);

#	endif
