/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:28:04 by rmei              #+#    #+#             */
/*   Updated: 2024/05/17 16:35:07 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Prints to screen the current variable, returns the n_chars printed */
static int	ft_print_arg(const char *fmt, va_list args, void *ptr)
{
	char	*hex_base;
	char	*hex_base_cap;

	hex_base = "0123456789abcdef";
	hex_base_cap = "0123456789ABCDEF";
	if (*fmt == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*fmt == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*fmt == 'p')
	{
		ptr = va_arg(args, void *);
		if (!ptr)
			return (ft_putstr("(nil)"));
		return (ft_putstr("0x") + ft_putnbr_base((unsigned long)ptr, hex_base));
	}
	else if (*fmt == 'd' || *fmt == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*fmt == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (*fmt == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), hex_base));
	else if (*fmt == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), hex_base_cap));
	return (ft_putchar(*fmt));
}

/* Manages printing 'cspdiuxX%' specifiers. Doesn't handle buffer size.
 * Returns the number of chars printed. */
int	ft_printf(const char *fmt, ...)
{
	int		n_chars;
	va_list	args;
	void	*ptr;

	n_chars = 0;
	ptr = NULL;
	va_start(args, fmt);
	while (*fmt)
	{
		while (*fmt && *fmt != '%')
		{
			ft_putchar(*fmt);
			n_chars++;
			fmt++;
		}
		if (!*fmt)
			break ;
		fmt++;
		n_chars += ft_print_arg(fmt, args, ptr);
		fmt++;
	}
	va_end(args);
	return (n_chars);
}
