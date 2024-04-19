/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:02:20 by rmei              #+#    #+#             */
/*   Updated: 2024/04/17 15:03:44 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Converts a character to lowercase (ASCII standard set), if possible */
int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c += 32;
	return (c);
}
