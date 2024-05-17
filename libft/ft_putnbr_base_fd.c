/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:08:16 by rmei              #+#    #+#             */
/*   Updated: 2024/05/17 12:38:20 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_is_base_valid(char *base)
{
	int	i;
	int	j;

	if (!*base || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] < '!' && base[i] > '~'))
			return (0);
		j = 0;
		while (base[j])
		{
			if (j != i && base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* Writes integer 'n' to 'fd' in a certain base, returns the n_chars printed */
int	ft_putnbr_base_fd(long n, int fd, char *base)
{
	int				n_chars;
	unsigned int	n_len;
	unsigned long	u_n;

	n_len = ft_strlen(base);
	if (!ft_is_base_valid(base))
		return (0);
	else
	{
		n_chars = 0;
		if (n < 0)
		{
			u_n = -n;
			write(fd, "-", 1);
			n_chars++;
		}
		else
			u_n = n;
		if (u_n / n_len)
			n_chars += ft_putnbr_base_fd(u_n / n_len, fd, base);
		write(fd, &base[u_n % n_len], 1);
		return (++n_chars);
	}
}
