/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 01:52:22 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/23 02:15:06 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_data(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->map_col_count * TILESIZE, data->map_row_count * TILESIZE, "so_long");
    data->counter = 1;
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
