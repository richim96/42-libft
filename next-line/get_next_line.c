/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:40 by rmei              #+#    #+#             */
/*   Updated: 2024/06/13 15:48:15 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_makebuffer(int fd, t_buffer *buffer, t_line *line)
{
	buffer->pos = 0;
	free(buffer->buffer);
	buffer->buffer = malloc(BUFFER_SIZE);
	if (!buffer->buffer)
	{
		buffer->end = 0;
		free(line->line);
		line->line = NULL;
		return ;
	}
	buffer->end = read(fd, buffer->buffer, BUFFER_SIZE);
	if (buffer->end <= 0)
	{
		free(buffer->buffer);
		buffer->buffer = NULL;
		if (buffer->end < 0)
		{
			free(line->line);
			line->line = NULL;
			return ;
		}
		if (line->line)
			line->line = ft_realloc(line->line, line->i + 1);
	}
}

static void	ft_makeline(t_buffer *buffer, t_line *line)
{
	while (buffer->pos < buffer->end)
	{
		if (!line->line || line->i >= (int)line->size - 1)
		{
			line->size *= 2;
			line->line = ft_realloc(line->line, line->size);
			if (!line->line)
				break ;
		}
		line->line[line->i++] = buffer->buffer[buffer->pos];
		line->line[line->i] = '\0';
		if (buffer->buffer[buffer->pos++] == '\n')
		{
			line->line = ft_realloc(line->line, line->i + 1);
			break ;
		}
	}
}

char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	t_line			line;

	line.i = 0;
	line.size = 64;
	line.line = NULL;
	while (1)
	{
		if (buffer.pos >= buffer.end)
			ft_makebuffer(fd, &buffer, &line);
		if (!buffer.buffer)
			return (line.line);
		ft_makeline(&buffer, &line);
		if (!line.line)
		{
			free(buffer.buffer);
			buffer.buffer = NULL;
			buffer.end = 0;
			return (NULL);
		}
		if (buffer.buffer[buffer.pos - 1] == '\n')
			return (line.line);
	}
}
