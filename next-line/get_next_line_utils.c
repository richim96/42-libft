/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:42 by rmei              #+#    #+#             */
/*   Updated: 2024/05/22 10:51:34 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Reallocates a memory block of size 'size', xcess memory is not initialized */
void	*ft_realloc(void *ptr, size_t size)
{
	int				i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr2 = malloc(size);
	if (!ptr2)
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (ptr2);
	i = 0;
	ptr1 = (unsigned char *)ptr;
	while (ptr1[i] && ptr2[i])
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	ptr2[i] = '\0';
	free(ptr);
	return (ptr2);
}

/* Takes the current line from a file descriptor */
char	*ft_makeline(int fd, char *buf, int pos, int end)
{
	char	*line;
	int		len;

	len = 1;
	while (1)
	{
		if (pos >= end)
		{
			end = read(fd, buf, BUFFER_SIZE);
			pos = 0;
			if (end <= pos)
				return (NULL);
		}
		while (pos < end && buf[pos] != '\n')
		{
			line = ft_realloc(line, len + 1);
			line[len++] = buf[pos++];
		}
		if (pos < end && buf[pos] == '\n')
		{
			pos++;
			line = ft_realloc(line, len + 1);
			line[len] = '\0';
			return (line);
		}
	}
}
