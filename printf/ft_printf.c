/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:28:04 by rmei              #+#    #+#             */
/*   Updated: 2024/05/13 16:29:13 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/* Manages printing 'cspdiuxX%' specifiers formatted with '-0.# +' flags and
 * width. Doesn't handle buffer size. Returns the number of chars printed. */
int	ft_printf(const char *format, ...)
{
	int		i;
	char	*s;

	s = (char *)format;
	i = 0;
	if (!ft_haschar(s, '%'))
	{
		ft_putstr_fd(s, 1);
		return (ft_strlen(format));
	}
	return (0);
}




#include <stdio.h>
int	main(void)
{
	char	*s = "hello dear, how are you?\n";

	ft_printf(s);
	//printf("Hello dear");
	return 0;
}
