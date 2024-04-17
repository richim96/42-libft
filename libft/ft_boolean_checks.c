/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:10:41 by rmei              #+#    #+#             */
/*   Updated: 2024/04/17 14:46:07 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks if a character is alphabetic (ASCII standard set) */
int	ft_isalpha(int c)
{
	return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}

/* Checks if a character is numeric */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* Checks if a character is either alphabetic (ASCII standard set) or numeric */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/* Checks if a character exists in the ASCII standard set */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/* Checks if a character is printable (ASCII standard set) */
int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
