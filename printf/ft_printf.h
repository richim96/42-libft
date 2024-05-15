/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:37:30 by rmei              #+#    #+#             */
/*   Updated: 2024/05/13 14:59:50 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int	ft_printf(const char *format, ...);

typedef struct s_spec
{
	int	c;
	int	s;
	int	p;
	int	d;
	int	i;
	int	u;
	int	x;
	int	x_cap;
	int	percent;
}	t_spec;

typedef struct s_flag {
	int	dash;
	int	zero;
	int	period;
	int	hash;
	int	space;
	int	plus;
}	t_flag;

#endif
