/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:21:40 by rmei              #+#    #+#             */
/*   Updated: 2024/05/10 11:45:19 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/* Erases data by setting n bytes of data at memory location s to 0 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = '\0';
}
