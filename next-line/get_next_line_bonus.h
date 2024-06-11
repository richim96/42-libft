/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:35:38 by rmei              #+#    #+#             */
/*   Updated: 2024/06/11 18:07:51 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_buffer
{
	char		*buffer;
	ssize_t		pos;
	ssize_t		end;
}	t_buffer;

typedef struct s_line
{
	char	*line;
	size_t	size;
	int		i;
}	t_line;

char		*get_next_line(int fd);
void		*ft_realloc(void *ptr, size_t size);

#endif
