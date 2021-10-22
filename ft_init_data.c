/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 01:52:22 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/23 03:00:28 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_data(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->map_col_count * TILESIZE, data->map_row_count * TILESIZE, "so_long");
    data->counter = 1;
}

void	set_map_path(t_data *data)
{
	data->img.player = mlx_xpm_file_to_image(data->mlx, "image/kirby.xpm",
			&data->img_width, &data->img_height);
	// if (!data->img.player)
		//print_errr(読み込めないよ！のERROR)
	data->img.freespace = mlx_xpm_file_to_image(data->mlx, "image/freespace.xpm",
			&data->img_width, &data->img_height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx,"image/starblock.xpm",
			&data->img_width, &data->img_height);
	data->img.collection = mlx_xpm_file_to_image(data->mlx, "image/Maximum.xpm",
			&data->img_width, &data->img_height);
	data->img.goal = mlx_xpm_file_to_image(data->mlx, "image/Star.xpm",
			&data->img_width, &data->img_height);
}

// static void	init_map_image(t_data *data)
// {
// 	data->img.player = NULL;
// 	data->img.freespace = NULL;
// 	data->img.wall = NULL;
// 	data->img.collection = NULL;
// 	data->img.goal = NULL;
// }

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
