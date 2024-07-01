/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:27:12 by rmei              #+#    #+#             */
/*   Updated: 2024/07/01 17:31:31 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

static int	ft_map_is_valid(char *map)
{
	int		fd;
	char	*line;
	size_t	n_rows;

	fd = open(map, O_RDONLY);
	line = ft_get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	n_rows = ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) != n_rows || !ft_isnumstr(line))
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (1);
}

static void	ft_map_draw(char *map)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (!map)
		return ;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 350, "LANDSCAPE WIREFRAME");
	mlx_loop(mlx_ptr);
}

int	main(int argc, char **argv)
{
	char	*error_msg;
	char	*map;

	error_msg = "[ERROR] : Invalid argument for map filepath\n";
	if (argc != 2)
	{
		write(2, error_msg, ft_strlen(error_msg));
		return (1);
	}
	map = argv[1];
	if (open(map, O_RDONLY) == -1)
	{
		perror("[SYS_ERROR]");
		return (1);
	}
	error_msg = "[ERROR] : Invalid map formatting\n";
	if (!ft_map_is_valid(map))
	{
		write(2, error_msg, ft_strlen(error_msg));
		return (1);
	}
	ft_map_draw(map);
	return (0);
}
