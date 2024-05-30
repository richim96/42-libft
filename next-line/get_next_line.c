/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:40 by rmei              #+#    #+#             */
/*   Updated: 2024/05/30 11:26:52 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Reads a line from 'fd', tracking which lines have already been read */
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	pos;
	static int	end;
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	while (1)
	{
		if (pos >= end)
		{
			pos = 0;
			end = read(fd, buffer, BUFFER_SIZE);
			if (end <= pos)
			{
				ft_bzero(buffer, sizeof(buffer));
				return (line);
			}
		}
		while (pos < end)
		{
			line = ft_realloc(line, i + 2);
			if (!line)
				return (NULL);
			line[i] = buffer[pos++];
			line[++i] = '\0';
			if (buffer[pos - 1] == '\n')
				return (line);
		}
	}
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
		printf("%s\n", line);
		line = get_next_line(fd);
	}
	printf("%s", line);
	return 0;
}*/
