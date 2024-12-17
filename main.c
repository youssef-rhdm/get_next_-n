/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:29:11 by yrhandou          #+#    #+#             */
/*   Updated: 2024/12/17 22:31:21 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void d()
{
	system("leaks a.out");
}
int main(void)
{
	atexit(d);
	int fd = open("file.txt", O_RDONLY);
	char *gnl;
	while ((gnl = get_next_line(fd)))
	{
		printf("%s\n", gnl);
		free(gnl);
	}
	return 0;
}
