/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:21:19 by rmei              #+#    #+#             */
/*   Updated: 2024/04/17 14:22:07 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks if a character is printable (ASCII standard set) */
int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
