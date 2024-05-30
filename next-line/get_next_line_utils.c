/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:42 by rmei              #+#    #+#             */
/*   Updated: 2024/05/30 10:52:28 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Erases data from a block of memory, setting it to 0 */
void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*((unsigned char *)s++) = '\0';
}

/* Reallocates memory to 'size', excess memory is not initialized */
void	*ft_realloc(void *ptr, size_t size)
{
	int				i;
	unsigned char 	*u_ptr;
	unsigned char	*ptr_new;

	ptr_new = malloc(size);
	if (!ptr_new)
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (ptr_new);
	i = 0;
	u_ptr = (unsigned char *)ptr;
	while (u_ptr[i])
	{
		ptr_new[i] = u_ptr[i];
		i++;
	}
	free(ptr);
	return (ptr_new);
}
