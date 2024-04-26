/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:07:19 by rmei              #+#    #+#             */
/*   Updated: 2024/04/25 15:50:06 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/* Counts the length of a given string, excluding the null terminator '\0' */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
