/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:35:38 by rmei              #+#    #+#             */
/*   Updated: 2024/06/07 20:34:13 by rmei             ###   ########.fr       */
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

typedef struct s_listgnl
{
	int					fd;
	t_buffer			buffer;
	struct s_listgnl	*next;
}	t_listgnl;

char		*get_next_line(int fd);
char		*ft_realloc(char *ptr, size_t size);
void		ft_lstgnl_add_back(t_listgnl **lst, t_listgnl *new);
t_listgnl	*ft_lstgnl_new(int fd);

#endif
