/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:40 by rmei              #+#    #+#             */
/*   Updated: 2024/05/25 12:54:45 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Reads a line from 'fd', tracking which lines have already been read */
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_pos;
	static int	buffer_end;

	buffer_pos = 0;
	buffer_end = 0;
	return (ft_makeline(fd, buffer, buffer_pos, buffer_end));
}

/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int	fd = open("./test", O_RDONLY);
	char *line = get_next_line(fd);

	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	printf("%s\n", line);
	return 0;
}*/
