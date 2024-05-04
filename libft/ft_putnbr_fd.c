/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:40:33 by rmei              #+#    #+#             */
/*   Updated: 2024/05/03 15:54:50 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

/* Outputs the integer 'n' to the file descriptor 'fd' */
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_n;
	char			char_n;

	u_n = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		u_n = -u_n;
	}
	if (u_n / 10)
		ft_putnbr_fd(u_n / 10, fd);
	char_n = (u_n % 10) + '0';
	write(fd, &char_n, 1);
}
