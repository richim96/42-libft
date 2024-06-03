/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:42 by rmei              #+#    #+#             */
/*   Updated: 2024/06/03 12:03:44 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE];
	int		pos;
	int		end;
}	t_buffer;

typedef struct s_line
{
	char	*line;
	int		i;
}	t_line;

char	*get_next_line(int fd);
void	*ft_realloc(void *ptr, size_t size);

#endif
