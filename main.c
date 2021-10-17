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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color) //自作関数pixelを代入する
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_data	data;

	data.relative_path = "image/kirby.xpm";
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "so_long");
	data.img = mlx_xpm_file_to_image(data.mlx, data.relative_path, &data.img_width, &data.img_height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	data.player_x = 0;
	data.player_y = 0;
	data.counter = 1;
	// int	y = 0;
	// int	x = 0;
	// while (y < 50)
	// {
	// 	while (x < 50)
	// 	{
	// 		my_mlx_pixel_put(&data, x, y, 0x00FF0000);
	// 		x++;
	// 	}
	// 	y++;
	// 	x = 0;
	// }
	mlx_put_image_to_window(data.mlx, data.win, data.img, 5, 5);
	mlx_key_hook(data.win, ft_key_hook, &data); //座標を変える
	//mlx_loop_hook(data.mlx, ft_loop_drew, &data); //roop_drewで描写を設定
	mlx_hook(data.win, 17, 1L<<17, ft_close, &data); //dataで座標の構造体管理をする
	mlx_loop(data.mlx);
	return (0);
}

