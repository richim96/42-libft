/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:14:59 by rmei              #+#    #+#             */
/*   Updated: 2024/04/17 14:17:07 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Checks if a character is either alphabetic (ASCII standard set) or numeric */
int	ft_isalnum(int c)
{
	return (ft_alpha(c) || ft_isdigit(c));
}
