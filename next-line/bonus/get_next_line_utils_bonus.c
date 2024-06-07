/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:36:38 by rmei              #+#    #+#             */
/*   Updated: 2024/06/07 15:43:40 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Looks for an existing reference to fd, returns the node if found */
static t_listgnl	*ft_node_fd(int fd, t_listgnl **lst)
{
	t_listgnl	*node;

	if (lst)
	{
		node = *lst;
		while (node->next)
		{
			if (node->fd == fd)
				return (node);
			node = node->next;
		}
	}
	return (NULL);
}

/* Creates a new node for a singly-linked gnl list */
t_listgnl	*ft_lstgnl_new(int fd, t_listgnl **lst)
{
	t_listgnl	*node;

	node = ft_node_fd(fd, lst);
	if (node)
		return (node);
	node = malloc(sizeof(t_listgnl));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->buffer.buffer = NULL;
	node->buffer.pos = 0;
	node->buffer.end = 0;
	node->next = NULL;
	return (node);
}

/* Adds a new to node to the end of the singly-linked gnl list */
void	ft_lstgnl_add_back(t_listgnl **lst, t_listgnl *new)
{
	t_listgnl	*node;

	if (!new)
		return ;
	if (!lst)
		lst = &new;
	else
	{
		node = *lst;
		while (node->next)
			node = node->next;
		node->next = new;
	}
}

/* Reallocates memory to 'size', excess memory is not initialized */
char	*ft_realloc(char *ptr, size_t size)
{
	size_t	i;
	char	*ptr_new;

	ptr_new = malloc(size);
	if (!ptr_new)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (ptr_new);
	i = 0;
	while (ptr[i] && i < size - 1)
	{
		ptr_new[i] = ptr[i];
		i++;
	}
	ptr_new[i] = '\0';
	free(ptr);
	return (ptr_new);
}
