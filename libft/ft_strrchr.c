/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:38:20 by rmei              #+#    #+#             */
/*   Updated: 2024/04/25 16:52:55 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns a pointer to the last occurence of c in s, or NULL. If c is '\0',
 * it returns a pointer to the null terminator. */
char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ptr_s;

	len = ft_strlen(s);
	ptr_s = (char *)s + len;
	if ((char)c == '\0')
		return (ptr_s);
	while (len >= 0)
	{
		if (*ptr_s == (char)c)
			return (ptr_s);
		ptr_s--;
		len--;
	}
	return (NULL);
}
