/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:42 by rmei              #+#    #+#             */
/*   Updated: 2024/05/25 12:49:10 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Reallocates memory to 'size', excess memory is not initialized */
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
	while (ptr1[i])
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	free(ptr);
	return (ptr2);
}

/* Takes the current line from a file descriptor */
char	*ft_makeline(int fd, char *buff, int pos, int end)
{
	char	*line;

	line = NULL;
	while (1)
	{
		if (pos >= end)
		{
			end = read(fd, buff, BUFFER_SIZE);
			pos = 0;
			if (end <= pos)
				return (NULL);
		}
		while (pos < end)
		{
			line = ft_realloc(line, pos + 2);
			line[pos] = buff[pos];
			line[++pos] = '\0';
		}
		if (buff[pos - 1] == '\n')
			return (line);
	}
}
