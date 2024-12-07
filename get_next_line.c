/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:59:28 by yrhandou          #+#    #+#             */
/*   Updated: 2024/12/07 18:12:25 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libc.h>

char *get_next_line(int fd)
{
	static char *buffer;
	int i =0;

	if (fd == -1)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE) ;
	if (!buffer)
		return NULL;
	int file_data = read(fd, buffer, BUFFER_SIZE);
	while (buffer[i]!='\n')
		i++;
	char *str = ft_substr(buffer, 0 ,i+1);
	if (!str)
		return NULL;
	return str;
}
