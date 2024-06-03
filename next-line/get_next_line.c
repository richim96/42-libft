/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:40 by rmei              #+#    #+#             */
/*   Updated: 2024/06/03 15:09:25 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

/* Creates the buffer to read the current line */
static void	*ft_makebuffer(int fd, t_buffer *pino, t_line *gnl)
{
	pino->pos = 0;
	free(pino->buffer);
	pino->buffer = malloc(BUFFER_SIZE);
	if (!pino->buffer)
		return (NULL);
	pino->end = read(fd, pino->buffer, BUFFER_SIZE);
	if (pino->end <= 0)
	{
		free(pino->buffer);
		pino->buffer = NULL;
		if (pino->end < 0)
		{
			free(gnl->line);
			return (NULL);
		}
	}
	return (gnl->line);
}

/* Reads a line from 'fd', tracking which lines have already been read */
char	*get_next_line(int fd)
{
	static t_buffer	pino;
	t_line			gnl;

	gnl.i = 0;
	gnl.line = NULL;
	while (1)
	{
		if (pino.pos >= pino.end)
			gnl.line = ft_makebuffer(fd, &pino, &gnl);
		if (pino.end <= 0)
			return (gnl.line);
		while (pino.pos < pino.end)
		{
			gnl.line = ft_realloc(gnl.line, gnl.i + 2, 1);
			if (!gnl.line)
				return (NULL);
			gnl.line[gnl.i++] = pino.buffer[pino.pos];
			gnl.line[gnl.i] = '\0';
			if (pino.buffer[pino.pos++] == '\n')
				return (gnl.line);
		}
	}
}
