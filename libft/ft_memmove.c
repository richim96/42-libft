/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:07:41 by rmei              #+#    #+#             */
/*   Updated: 2024/04/25 14:58:17 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

/* Copies n bytes to memory area dest from memory area src. Memory can overlap:
 * the bytes from src are first copied in a temporary, non-overlapping array,
 * then the bytes are copied to dest. Returns a pointer to dest. */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_arr;

	temp_arr = (unsigned char *)malloc(n * sizeof(unsigned char));
	if (!temp_arr)
		return (NULL);
	i = 0;
	while (i < n)
	{
		temp_arr[i] = ((unsigned char *)src)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = temp_arr[i];
		i++;
	}
	free(temp_arr);
	return (dest);
}
