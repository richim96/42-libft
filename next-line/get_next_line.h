/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:42 by rmei              #+#    #+#             */
/*   Updated: 2024/06/07 20:33:30 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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

char	*get_next_line(int fd);
char	*ft_realloc(char *ptr, size_t size);

#endif
