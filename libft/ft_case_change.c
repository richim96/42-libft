/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:55:28 by rmei              #+#    #+#             */
/*   Updated: 2024/04/17 15:00:49 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts a character to uppercase, if possible */
int	ft_toupper(int c)
{
	if (c >= 'a' && <= 'z')
		c -= 32;
	return (c);
}

/* Converts a character to lowercase, if possible */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
