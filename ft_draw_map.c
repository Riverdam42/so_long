/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:18:58 by kkawano           #+#    #+#             */
/*   Updated: 2021/11/06 04:58:23 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.ground, \
				x * TILESIZE, y * TILESIZE);
	if (data->map[y][x] == 'P')
	{
		data->player_x = x;
		data->player_y = y;
		mlx_put_image_to_window(data->mlx, data->win, data->img.player, \
				data->player_x * TILESIZE, data->player_y * TILESIZE);
	}
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.collect, \
				x * TILESIZE, y * TILESIZE);
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.goal, \
				x * TILESIZE, y * TILESIZE);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall, \
				x * TILESIZE, y * TILESIZE);
}

int	ft_draw_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map_row_count)
	{
		x = -1;
		while (++x < data->map_col_count)
		{
			draw_image(data, x, y);
		}
	}
	return (0);
}
