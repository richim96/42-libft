/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:35:54 by rmei              #+#    #+#             */
/*   Updated: 2024/06/11 12:53:52 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

#include "get_next_line_bonus.h"

static	t_listgnl	*ft_makenode(int fd, t_listgnl **lst)
{
	t_listgnl	*node;

	node = ft_node_fd(fd, lst);
	if (!node)
	{
		node = ft_lst_new(fd);
		if (node)
			ft_lst_add_back(lst, node);
	}
	return (node);
}

static void	ft_makebuffer(int fd, t_buffer *buffer, t_line *gnl)
{
	buffer->pos = 0;
	free(buffer->buffer);
	buffer->buffer = malloc(BUFFER_SIZE);
	if (!buffer->buffer)
	{
		free(gnl->line);
		gnl->line = NULL;
		return ;
	}
	buffer->end = read(fd, buffer->buffer, BUFFER_SIZE);
	if (buffer->end <= 0)
	{
		free(buffer->buffer);
		buffer->buffer = NULL;
		if (buffer->end < 0)
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
				break ;
		}
		gnl->line[gnl->i++] = buffer->buffer[buffer->pos];
		gnl->line[gnl->i] = '\0';
		if (buffer->buffer[buffer->pos++] == '\n')
		{
			gnl->line = ft_realloc(gnl->line, gnl->i + 1);
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

	node = ft_makenode(fd, lst);
	if (!node)
		return (NULL);
	gnl.i = 0;
	gnl.size = 64;
	gnl.line = NULL;
	while (1)
	{
		if (node->buffer.pos >= node->buffer.end)
			ft_makebuffer(fd, &node->buffer, &gnl);
		//printf("\nPOOPY POOP");
		if (!node->buffer.buffer)
		{
			free(node);
			return (gnl.line);
		}
		//printf("\n||| DIGGITY DIG");
		ft_makeline(&node->buffer, &gnl);
		if (!gnl.line)
		{
			free(node->buffer.buffer);
			free(node);
			return (NULL);
		}
		if (node->buffer.buffer[node->buffer.pos - 1] == '\n')
			return (gnl.line);
	}
}
