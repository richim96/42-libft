/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:40 by rmei              #+#    #+#             */
/*   Updated: 2024/06/07 20:34:36 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

#include "get_next_line.h"

#include <stdio.h>
static void	ft_makebuffer(int fd, t_buffer *buffer, t_line *gnl)
{
	buffer->pos = 0;
	free(buffer->buffer);
	buffer->buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer->buffer)
		return ;
	buffer->end = read(fd, buffer->buffer, BUFFER_SIZE);
	if (buffer->end <= 0)
	{
		free(buffer->buffer);
		buffer->buffer = NULL;
		if (buffer->end == -1)
		{
			free(gnl->line);
			gnl->line = NULL;
			return ;
		}
		if (gnl->line)
			gnl->line = ft_realloc(gnl->line, gnl->i + 1);
	}
}

static void	ft_makeline(t_buffer *buffer, t_line *gnl)
{
	while (buffer->pos < buffer->end)
	{
		if (!gnl->line || gnl->i >= (int)gnl->size - 1)
		{
			gnl->size *= 2;
			gnl->line = ft_realloc(gnl->line, gnl->size);
			if (!gnl->line)
			{
				free(buffer->buffer);
				buffer->buffer = NULL;
				break ;
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
			break ;
		}
	}
}

char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	t_line			gnl;

	gnl.i = 0;
	gnl.size = 64;
	gnl.line = NULL;
	while (1)
	{
		//printf("BUFFER END PRE MANNAGGIA: %d\n", buffer.end);
		if (buffer.pos >= buffer.end)
			ft_makebuffer(fd, &buffer, &gnl);
		//printf(" * BUFFER END: %d\n", buffer.end);
		if (!buffer.buffer || buffer.end <= 0)
			return (gnl.line);
		//printf("BUFFER BUFFER: %s\n", buffer.buffer);
		ft_makeline(&buffer, &gnl);
		if (!gnl.line)
			return (NULL);
		if (buffer.buffer[buffer.pos - 1] == '\n')
			return (gnl.line);
	}
}
