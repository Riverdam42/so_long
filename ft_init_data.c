/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:48:28 by kkawano           #+#    #+#             */
/*   Updated: 2021/11/06 21:48:35 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->player_num = 0;
	data->counter = 1;
	data->goal_num = 0;
	data->goal_flag = 0;
	data->map_col_count = 0;
	data->map_row_count = 0;
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		print_error("MLX initialization failed!!\n");
	data->win = mlx_new_window(data->mlx, data->map_col_count * TILESIZE, \
			data->map_row_count * TILESIZE, "so_long");
}

void	set_map_path(t_data *data)
{
	data->img.player = mlx_xpm_file_to_image(data->mlx, "image/kirby.xpm",
			&data->img_width, &data->img_height);
	if (!data->img.player)
		print_error("Failed to retrieve player image!");
	data->img.ground = mlx_xpm_file_to_image(data->mlx, "image/freespace.xpm",
			&data->img_width, &data->img_height);
	if (!data->img.ground)
		print_error("Failed to retrieve ground image!");
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "image/starblock.xpm",
			&data->img_width, &data->img_height);
	if (!data->img.wall)
		print_error("Failed to retrieve wall image!");
	data->img.collect = mlx_xpm_file_to_image(data->mlx, "image/Maximum.xpm",
			&data->img_width, &data->img_height);
	if (!data->img.collect)
		print_error("Failed to retrieve collect image!");
	data->img.goal = mlx_xpm_file_to_image(data->mlx, "image/Star.xpm",
			&data->img_width, &data->img_height);
	if (!data->img.goal)
		print_error("Failed to retrieve goal image!");
}
