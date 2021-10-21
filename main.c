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

	ft_read_map(&data, "./maps/pdf.ber");
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "so_long");
	data.player_x = 0;
	data.player_y = 0;
	data.counter = 1;
	set_map_path(&data);
 	mlx_put_image_to_window(data.mlx, data.win, data.img.goal, 5, 5);
	//mlx_key_hook(data.win, ft_key_hook, &data); //座標を変える
	//mlx_loop_hook(data.mlx, ft_loop_drew, &data); //roop_drewで描写を設定
	mlx_hook(data.win, 17, 1L<<17, ft_close, &data); //dataで座標の構造体管理をする
	mlx_loop(data.mlx);
	return (0);
}
