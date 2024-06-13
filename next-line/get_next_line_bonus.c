/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:35:54 by rmei              #+#    #+#             */
/*   Updated: 2024/06/13 16:52:32 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
			line->size *= 4;
			line->line = ft_realloc(line->line, line->size);
			if (!line->line)
			{
				free(buffer->buffer);
				buffer->buffer = NULL;
				break ;
			}
		}
		line->line[line->i++] = buffer->buffer[buffer->pos];
		line->line[line->i] = '\0';
		if (buffer->buffer[buffer->pos++] == '\n')
		{
			line->line = ft_realloc(line->line, line->i + 1);
			if (!line->line)
				free(buffer->buffer);
			if (!line->line)
				buffer->buffer = NULL;
			break ;
		}
	}
}

char	*get_next_line(int fd)
{
	static t_buffer	fd_arr[1024];
	t_buffer		*buffer;
	t_line			line;

	if (fd < 0 || fd > 1024)
		return (NULL);
	line.i = 0;
	line.size = 128;
	line.line = NULL;
	buffer = &fd_arr[fd];
	while (1)
	{
		if (buffer->pos >= buffer->end)
			ft_makebuffer(fd, buffer, &line);
		if (!buffer->buffer)
			return (line.line);
		ft_makeline(buffer, &line);
		if (!line.line)
		{
			buffer->end = 0;
			return (NULL);
		}
		if (buffer->buffer[buffer->pos - 1] == '\n')
			return (line.line);
	}
}
