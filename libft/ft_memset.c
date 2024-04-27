/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:38:34 by rmei              #+#    #+#             */
/*   Updated: 2024/04/26 18:35:25 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/* Fills the first n bytes of the memory area pointed to by s with the constant
 * byte c. Returns a pointer to the memory area s. */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
	{
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (s);
}
