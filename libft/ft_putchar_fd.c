/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:13:57 by rmei              #+#    #+#             */
/*   Updated: 2024/05/03 15:17:56 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* Outputs the character 'c' to the file descriptor 'fd' */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}