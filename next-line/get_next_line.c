/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:40 by rmei              #+#    #+#             */
/*   Updated: 2024/05/31 17:15:42 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Creates the buffer to read the current line */
static char	*ft_makebuffer(int fd, t_buffer *pino, t_line *gnl)
{
	pino->pos = 0;
	pino->end = read(fd, pino->buffer, BUFFER_SIZE);
	if (pino->end <= 0)
	{
		ft_bzero(pino->buffer, sizeof pino->buffer);
		if (pino->end < 0)
		{
			if (gnl->line)
				free(gnl->line);
			return (NULL);
		}
	}
	return (gnl->line);
}

/* Reads the current line from the buffer */
static void	ft_makeline(t_buffer *pino, t_line *gnl)
{
	while (pino->pos < pino->end)
	{
		gnl->line = ft_realloc(gnl->line, gnl->i + 2);
		if (!gnl->line)
			break ;
		gnl->line[gnl->i++] = pino->buffer[pino->pos++];
		gnl->line[gnl->i] = '\0';
		if (pino->buffer[pino->pos - 1] == '\n')
			break ;
	}
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
		ft_makeline(&pino, &gnl);
		if (pino.buffer[pino.pos - 1] == '\n')
			return (gnl.line);
	}
}
