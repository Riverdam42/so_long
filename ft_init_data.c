/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 01:52:22 by kkawano           #+#    #+#             */
/*   Updated: 2021/11/06 06:03:06 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_col_count * TILESIZE, \
			data->map_row_count * TILESIZE, "so_long");
	data->player_num = 0;
	data->counter = 1;
}

void	set_map_path(t_data *data)
{
	data->img.player = mlx_xpm_file_to_image(data->mlx, "image/kirby.xpm",
			&data->img_width, &data->img_height);
	if (!data->img.player)
		print_error("Failed to retrieve player image");
	data->img.ground = mlx_xpm_file_to_image(data->mlx, "image/freespace.xpm",
			&data->img_width, &data->img_height);
	if (!data->img.ground)
		print_error("Failed to retrieve ground image");
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "image/starblock.xpm",
			&data->img_width, &data->img_height);
	if (!data->img.wall)
		print_error("Failed to retrieve wall image");
	data->img.collect = mlx_xpm_file_to_image(data->mlx, "image/Maximum.xpm",
			&data->img_width, &data->img_height);
	if (!data->img.collect)
		print_error("Failed to retrieve collect image");
	data->img.goal = mlx_xpm_file_to_image(data->mlx, "image/Star.xpm",
			&data->img_width, &data->img_height);
	if (!data->img.goal)
		print_error("Failed to retrieve goal image");
}

// static void init_data(t_data)
// {
//     data->*map = NULL;
// 	data->mlx = NULL;
// 	data->win = NULL;
// 	data->addr = NULL;
// 	data->img_width = NULL;
// 	data->img_height = NULL;
// 	data->bits_per_pixel = NULL;
// 	data->line_length = NULL;
// 	data->map_row_count = NULL;
// 	data->map_col_count = NULL;
// 	data->endian = NULL;
// 	int		player_x;
// 	int		player_y;
// 	int		counter;
// }
