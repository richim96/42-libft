/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:21:40 by rmei              #+#    #+#             */
/*   Updated: 2024/04/25 12:27:27 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/* Erases data by setting n bytes of data at memory location s to zero ('\0') */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}
