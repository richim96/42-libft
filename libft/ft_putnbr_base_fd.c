/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:08:16 by rmei              #+#    #+#             */
/*   Updated: 2024/05/13 13:03:28 by rmei             ###   ########.fr       */
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

/* Writes a number 'n' to a file descriptor in a certain base */
void	ft_putnbr_base_fd(int n, int fd, char *base)
{
	unsigned int	n_len;
	unsigned int	u_n;

	n_len = ft_strlen(base);
	if (!ft_is_base_valid(base))
		write(2, "", 0);
	else
	{
		if (n < 0)
		{
			u_n = -n;
			write(fd, "-", 1);
		}
		else
			u_n = n;
		if (u_n / n_len)
			ft_putnbr_base_fd(u_n / n_len, fd, base);
		write(fd, &base[u_n % n_len], 1);
	}
}
