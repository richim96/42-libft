/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:35:54 by rmei              #+#    #+#             */
/*   Updated: 2024/06/07 12:31:43 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

static void	ft_makebuffer(int fd, t_buffer *buffer, t_line *gnl)
{
	buffer->pos = 0;
	free(buffer->buffer);
	buffer->buffer = malloc(BUFFER_SIZE);
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

#include <stdio.h>
char	*get_next_line(int fd)
{
	static t_listgnl	**lst;
	t_listgnl			*node;
	t_line				gnl;

	node = ft_is_fd(lst, fd);
	if (!node)
	{
		node = ft_lstgnl_new(fd);
		ft_lstgnl_add_back(lst, node);
	}
	gnl.i = 0;
	gnl.size = 64;
	gnl.line = NULL;
	while (1)
	{
		if (node->buffer.pos >= node->buffer.end)
			ft_makebuffer(fd, &node->buffer, &gnl);
		if (node->buffer.end <= 0)
			return (gnl.line);
		if (!node->buffer.buffer)
			return (NULL);
		ft_makeline(&node->buffer, &gnl);
		if (!gnl.line)
			return (NULL);
		if (node->buffer.buffer[node->buffer.pos - 1] == '\n')
			return (gnl.line);
	}
}
