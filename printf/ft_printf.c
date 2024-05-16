/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:28:04 by rmei              #+#    #+#             */
/*   Updated: 2024/05/16 17:33:30 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

//static char	*g_flags;

//g_flags = "-0.# +";

//static void	ft_set_flags(char *s);
//static char	*ft_print_flags(char *s, char *s_var);

/* Prints to screen the current variable */
static void ft_print_arg(const char *fmt, va_list args)
{
	char	*var;
	
	if (*fmt == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*fmt == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*fmt == 'd' || *fmt == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*fmt == 'x')
		ft_putnbr_base_fd(va_arg(args, int), 1, "0123456789abcdef");
	else if (*fmt == 'X')
		ft_putnbr_base_fd(va_arg(args, int), 1, "0123456789ABCDEF");
	else
		ft_putchar_fd(*fmt, 1);
}

//static char	*ft_ptr_shift(char *s);

/* Manages printing 'cspdiuxX%' specifiers formatted with '-0.# +' flags and
 * width. Doesn't handle buffer size. Returns the number of chars printed. */
int	ft_printf(const char *fmt, ...)
{
	int		n_chars;
	char	*var;
	va_list	args;

	n_chars = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		while (*fmt && *fmt != '%')
		{
			ft_putchar_fd(*fmt, 1);
			n_chars++;
			fmt++;
		}
		if (!*fmt)
			break ;
		fmt++;
		ft_print_arg(fmt, args);
		fmt++;
	}
	va_end(args);
	return (n_chars);
}

int	main(void)
{
	ft_printf("Hello %% %c %c dear, %i%d, %x %X \n", 'm', 'y', 10, 11, 1000, 1200);
	printf("Hello %% %c %c dear, %i%d, %x %X\n", 'm', 'y', 10, 11, 1000, 1200);
	return 0;
}
