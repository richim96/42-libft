/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:20:21 by rmei              #+#    #+#             */
/*   Updated: 2024/04/26 18:21:58 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

/* Allocates memory (set to 0) for an array of nmemb elements of size bytes.
 * Returns a ptr to the allocated memory, or NULL if either nmemb or size is 0.
 * If (nmemb * size) would cause integer overflow, it returns an error. */
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	*array;

	if (!nmemb || !size)
		return (NULL);
	if (nmemb * size < nmemb || nmemb * size < size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	array = (void *) malloc(nmemb * size);
	if (!array)
		return (NULL);
	while (nmemb)
		array[--nmemb] = 0;
	return ((void *)array);
}
