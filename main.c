/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:53:01 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/11 22:31:1:03 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	data;

	ft_read_map(&data, "pdf.ber");
	data.relative_path = "image/kirby.xpm";
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "so_long");
	data.img = mlx_xpm_file_to_image(data.mlx, data.relative_path, &data.img_width, &data.img_height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	data.player_x = 0;
	data.player_y = 0;
	data.counter = 1;
	mlx_put_image_to_window(data.mlx, data.win, data.img, 5, 5);
	mlx_key_hook(data.win, ft_key_hook, &data); //座標を変える
	//mlx_loop_hook(data.mlx, ft_loop_drew, &data); //roop_drewで描写を設定
	mlx_hook(data.win, 17, 1L<<17, ft_close, &data); //dataで座標の構造体管理をする
	mlx_loop(data.mlx);
	return (0);
}

// void	set_map_path(t_data *data)
// {
// 	data->map_image.player = "images/kirby.xpm";
// 	data->map_image.freespace = "images/freespace.xpm"; //まだ決まってない
// 	data->map_image.wall = "images/starblock.xpm";
// 	data->map_image.collection = "images/Maxmum.xpm";
// 	data->map_image.goal = "images/Star.xpm";
// 	data->img.s_img = mlx_xpm_file_to_image(data->mlx, data->map_image.freespace,
// 			&data->img.width, &data->img.height);
// 	data->img.w_img = mlx_xpm_file_to_image(data->mlx, data->map_image.wall,
// 			&data->img.width, &data->img.height);
// 	data->img.c_img = mlx_xpm_file_to_image(data->mlx, data->map_image.collection,
// 			&data->img.width, &data->img.height);
// 	data->img.e_img = mlx_xpm_file_to_image(data->mlx, data->map_image.goal,
// 			&data->img.width, &data->img.height);
// 	data->img.p_img = mlx_xpm_file_to_image(data->mlx, data->map_image.player,
// 			&data->img.width, &data->img.height);
// }
