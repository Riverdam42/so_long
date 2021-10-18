/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:44:21 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/18 09:32:13 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//readでmapを読み込んでいく

static void	map_image_init(t_data *data)
{
	data->map = 0;
	data->mlx = 0;
	data->mlx_win = 0;
	data->img.player = 0;
	data->img.freespace = 0;
	data->img.wall = 0;
	data->img.collection = 0;
	data->img.goal = 0;
}

void	set_map_path(t_data *data)
{
	data->map_image.player = "images/kirby.xpm";
	data->map_image.freespace = "images/space.xpm"; //まだ決まってない
	data->map_image.wall = "images/starblock.xpm";
	data->map_image.collection = "images/Maxmum.xpm";
	data->map_image.goal = "images/goal.xpm"; //もう少しでできそう
	data->img.s_img = mlx_xpm_file_to_image(data->mlx, data->map_image.freespace,
			&data->img.width, &data->img.height);
	data->img.w_img = mlx_xpm_file_to_image(data->mlx, data->map_image.wall,
			&data->img.width, &data->img.height);
	data->img.c_img = mlx_xpm_file_to_image(data->mlx, data->map_image.collection,
			&data->img.width, &data->img.height);
	data->img.e_img = mlx_xpm_file_to_image(data->mlx, data->map_image.goal,
			&data->img.width, &data->img.height);
	data->img.p_img = mlx_xpm_file_to_image(data->mlx, data->map_image.player,
			&data->img.width, &data->img.height);
}