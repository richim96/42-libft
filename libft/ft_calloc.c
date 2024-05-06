/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:20:21 by rmei              #+#    #+#             */
/*   Updated: 2024/05/06 20:01:34 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* Allocates memory (set to 0) for a group of *n members* of *size* bytes.
 * Returns a ptr to the allocated memory. If the memory required would cause
 * overflow, 'nmemb' or 'size' is 0, or memory allocation fails, returns NULL */
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	mem_req;
	void	*ptr;

	mem_req = nmemb * size;
	if (mem_req < nmemb || mem_req < size)
		return (NULL);
	ptr = (void *) malloc(mem_req * sizeof(void));
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, mem_req);
	return (ptr);
}
