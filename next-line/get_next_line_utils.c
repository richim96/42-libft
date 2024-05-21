/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:42 by rmei              #+#    #+#             */
/*   Updated: 2024/05/21 17:36:54 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(void *ptr, size_t size)
{
	int				i;
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
	while (((unsigned char *)ptr)[i])
	{
		ptr2[i] = ((unsigned char *)ptr)[i];
		i++;
	}
	ptr2[i] = '\0';
	free(ptr);
	return (ptr2);
}

#include <stdio.h>
int	main(void)
{
	char	*ptr = NULL; //malloc(3)
	char	*ptr2;

	/*ptr[0] = 'H';
	ptr[1] = 'T';
	ptr[2] = '\0';*/
	ptr2 = ft_realloc(ptr, 14);
	printf("%s\n", ptr2);
	free(ptr2);
	return (0);
}

/*
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
}*/
