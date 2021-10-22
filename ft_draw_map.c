/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:18:58 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/23 02:55:20 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'P')
	{
        data->player_x = x * TILESIZE;
        data->player_y = y * TILESIZE;
    }
    else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.collection, x * TILESIZE, y * TILESIZE);
	else if (data->map[y][x] == 'E')
        mlx_put_image_to_window(data->mlx, data->win, data->img.goal, x * TILESIZE, y * TILESIZE);
	else if (data->map[y][x] == '0')
        mlx_put_image_to_window(data->mlx, data->win, data->img.freespace, x * TILESIZE, y * TILESIZE);
    else if (data->map[y][x] == '1')
        mlx_put_image_to_window(data->mlx, data->win, data->img.wall, x * TILESIZE, y * TILESIZE);
    mlx_put_image_to_window(data->mlx, data->win, data->img.player, data->player_x, data->player_y);
}

int     ft_draw_map(t_data *data)
{
    int x;
    int y;

    y = -1;
    while(++y < data->map_row_count)
    {
        x = -1;
        while (++x < data->map_col_count)
        {
            draw_image(data, x, y);
        }
    }
    return (0);
//     if (エラーマップだったとき)
//     print_error("Error\n, Invalid map");
}
