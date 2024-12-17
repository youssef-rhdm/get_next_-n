/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:59:28 by yrhandou          #+#    #+#             */
/*   Updated: 2024/12/17 22:41:42 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_one_line(const char *str)
{
	char *line;
	int i;

	if (!str || str[0] == '\0')
		return NULL;
	i = 0;
	line = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!line)
		return NULL;
	while (str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return line;
}

static char *leftovers(const char *s)
{
	char *start;

	if (!s || s[0] == '\0')
		return (NULL);
	start = ft_strchr(s, '\n') + 1;
	free((void *)s);
	if (*start == '\0')
		return NULL;
	return start;
}

char *get_next_line(int fd)
{
	static char *bag;
	char *buffer;
	int byte_count;
	char *line;
	char *temp;

	buffer = malloc(BUFFER_SIZE +1);
	if (fd < 0 || fd > INT_MAX || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0||!buffer)
		return NULL;
	byte_count = 1;
	while (byte_count != 0 && ft_strchr(bag, '\n') == NULL)
	{
		byte_count = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_count] = '\0';
		temp = bag;
		bag = ft_strjoin(bag, buffer);
		free(temp);
	}
	line = get_one_line(bag);
	bag = leftovers(bag);
	return line;
}
