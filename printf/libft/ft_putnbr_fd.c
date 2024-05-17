/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:40:33 by rmei              #+#    #+#             */
/*   Updated: 2024/05/17 12:38:36 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

/* Prints integer 'n' to the file descriptor 'fd', returns n_chars printed */
int	ft_putnbr_fd(long n, int fd)
{
	int				n_chars;
	unsigned long	u_n;
	char			char_n;

	n_chars = 0;
	u_n = n;
	if (n < 0)
	{
		u_n = -u_n;
		write(fd, "-", 1);
		n_chars++;
	}
	if (u_n / 10)
		n_chars += ft_putnbr_fd(u_n / 10, fd);
	char_n = (u_n % 10) + '0';
	write(fd, &char_n, 1);
	return (++n_chars);
}
