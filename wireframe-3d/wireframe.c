/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:14:12 by rmei              #+#    #+#             */
/*   Updated: 2024/07/02 18:28:54 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

static t_img	ft_img_make(void *mlx_ptr)
{
	t_img	img;

	img.img_ptr = mlx_new_image(mlx_ptr, 500, 375);
	img.img_addr = mlx_get_data_addr(
			img.img_ptr,
			&img.bits_per_pixel,
			&img.size_line,
			&img.endian
			);
	return (img);
}

void	ft_map_draw(char *map)
{
	int		fd;
	char	*row;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;

	fd = open(map, O_RDONLY);
	row = ft_get_next_line(fd);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 750, map);
	img = ft_img_make(mlx_ptr);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}
