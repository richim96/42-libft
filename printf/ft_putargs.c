/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:13:57 by rmei              #+#    #+#             */
/*   Updated: 2024/05/17 16:26:31 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Counts the length of a given string, excluding the null terminator '\0' */
size_t	ft_strlen(const char *s)
{
	if (!*s)
		return (0);
	return (1 + ft_strlen(++s));
}

/* Outputs the character 'c' to stdout, returns 1 */
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/* Prints 's' to stdout, returns n_chars printed */
int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

/* Prints integer 'n' to stdout, returns n_chars printed */
int	ft_putnbr(long n)
{
	int				n_chars;
	unsigned long	u_n;
	char			char_n;

	n_chars = 0;
	u_n = n;
	if (n < 0)
	{
		u_n = -u_n;
		write(1, "-", 1);
		n_chars++;
	}
	if (u_n / 10)
		n_chars += ft_putnbr(u_n / 10);
	char_n = (u_n % 10) + '0';
	write(1, &char_n, 1);
	return (++n_chars);
}

/* Writes 'n' to stdout in a certain base, returns the n_chars printed */
int	ft_putnbr_base(unsigned long n, char *base)
{
	int				n_chars;
	unsigned int	n_len;

	n_len = ft_strlen(base);
	n_chars = 0;
	if (n / n_len)
		n_chars += ft_putnbr_base(n / n_len, base);
	write(1, &base[n % n_len], 1);
	return (++n_chars);
}
