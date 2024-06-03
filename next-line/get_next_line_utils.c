/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:42 by rmei              #+#    #+#             */
/*   Updated: 2024/06/03 15:04:54 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Reallocates memory to 'size', excess memory is not initialized */
void	*ft_realloc(void *ptr, size_t size, size_t size_diff)
{
	size_t			i;
	unsigned char	*u_ptr;
	unsigned char	*ptr_new;

	ptr_new = malloc(size);
	if (!ptr_new)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (ptr_new);
	i = 0;
	u_ptr = (unsigned char *)ptr;
	while (i < size - size_diff)
	{
		ptr_new[i] = u_ptr[i];
		i++;
	}
	free(ptr);
	return (ptr_new);
}
