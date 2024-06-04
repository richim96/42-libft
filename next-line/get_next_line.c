/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:40 by rmei              #+#    #+#             */
/*   Updated: 2024/06/04 19:23:55 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

/* Creates the buffer to read the current line */
static char	*ft_makebuffer(int fd, t_buffer *buffer, t_line *gnl)
{
	buffer->pos = 0;
	free(buffer->buffer);
	buffer->buffer = malloc(BUFFER_SIZE);
	if (!buffer->buffer)
		return (NULL);
	buffer->end = read(fd, buffer->buffer, BUFFER_SIZE);
	if (buffer->end <= 0)
	{
		free(buffer->buffer);
		buffer->buffer = NULL;
		if (buffer->end == 0 && gnl->line)
			gnl->line = ft_realloc(gnl->line, gnl->i + 1);
		if (buffer->end < 0)
		{
			free(gnl->line);
			return (NULL);
		}
	}
	return (gnl->line);
}

/* Reads the current line from the buffer */
static void	ft_makeline(t_buffer *buffer, t_line *gnl)
{
	while (buffer->pos < buffer->end)
	{
		if (!gnl->line || gnl->i >= gnl->size - 1)
		{
			gnl->size *= 2;
			gnl->line = ft_realloc(gnl->line, gnl->size);
			if (!gnl->line)
			{
				free(buffer->buffer);
				buffer->buffer = NULL;
				return ;
			}
		}
		gnl->line[gnl->i++] = buffer->buffer[buffer->pos];
		gnl->line[gnl->i] = '\0';
		if (buffer->buffer[buffer->pos++] == '\n')
		{
			gnl->line = ft_realloc(gnl->line, gnl->i + 1);
			if (!gnl->line)
				free(buffer->buffer);
			if (!gnl->line)
				buffer->buffer = NULL;
			return ;
		}
	}
}

/* Reads a line from 'fd', tracking which lines have already been read */
char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	t_line			gnl;

	gnl.i = 0;
	gnl.size = 512;
	gnl.line = NULL;
	while (1)
	{
		if (buffer.pos >= buffer.end)
			gnl.line = ft_makebuffer(fd, &buffer, &gnl);
		if (buffer.end <= 0)
			return (gnl.line);
		ft_makeline(&buffer, &gnl);
		if (!gnl.line || buffer.buffer[buffer.pos - 1] == '\n')
			return (gnl.line);
	}
}
