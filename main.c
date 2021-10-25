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
	init_data(&data);
	set_map_path(&data);
	ft_draw_map(&data);
	mlx_key_hook(data.win, ft_key_hook, &data);
	mlx_hook(data.win, 17, 1L<<17, ft_close_map, &data); //dataで座標の構造体管理をする
	mlx_loop(data.mlx);
	return (0);
}
