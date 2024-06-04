/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:42 by rmei              #+#    #+#             */
/*   Updated: 2024/06/04 17:21:42 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
