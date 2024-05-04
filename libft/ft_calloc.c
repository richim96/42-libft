/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:20:21 by rmei              #+#    #+#             */
/*   Updated: 2024/05/03 16:32:07 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* Allocates memory (set to 0) for a group of *n members* of *size* bytes.
 * Returns a ptr to the allocated memory, or a unique ptr in case either nmemb
 * or size is 0. If the memory required would cause integer overflow, returns
 * NULL. If the allocation fails, sets errno to ENOMEM and returns NULL. */
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	mem_req;
	void	*ptr;

	mem_req = nmemb * size;
	if (mem_req < nmemb || mem_req < size)
		return (NULL);
	if (!nmemb || !size)
		ptr = (void *) malloc(sizeof(void));
	else
		ptr = (void *) malloc(mem_req * sizeof(void));
	if (!ptr)
		return (NULL);
	if (mem_req)
		ft_memset(ptr, 0, mem_req);
	return (ptr);
}
