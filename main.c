/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:29:11 by yrhandou          #+#    #+#             */
/*   Updated: 2024/12/21 16:45:40 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libc.h>

void	d(void)
{
	system("leaks a.out");
}
int	main(void)
{
	char *gnl;

	atexit(d);
	int fd = open("./tests/read_error.txt", O_RDONLY);
	for(int i = 0;i <6 ; i++)
	{
		gnl = get_next_line(fd);
		printf("%s", gnl);
		free(gnl);
	}
	return 0;
}
