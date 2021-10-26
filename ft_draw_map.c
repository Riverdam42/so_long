/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:18:58 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/26 11:21:14 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_data *data, int x, int y)
{
    mlx_put_image_to_window(data->mlx, data->win, data->img.freespace, x * TILESIZE, y * TILESIZE);
    if (data->map[y][x] == 'P')
	{
        data->player_x = x;
        data->player_y = y;
        mlx_put_image_to_window(data->mlx, data->win, data->img.player, data->player_x * TILESIZE, data->player_y * TILESIZE);
    }
    else if (data->map[y][x] == 'C')
    {
        //data->count.collectible++;
        //printf("collectible:%d\n", data->count.collectible);
		mlx_put_image_to_window(data->mlx, data->win, data->img.collection, x * TILESIZE, y * TILESIZE);
    }
    else if (data->map[y][x] == 'E')
        mlx_put_image_to_window(data->mlx, data->win, data->img.goal, x * TILESIZE, y * TILESIZE);
    else if (data->map[y][x] == '1')
        mlx_put_image_to_window(data->mlx, data->win, data->img.wall, x * TILESIZE, y * TILESIZE);
    // else if (data->map[y][x] != MAP_SYMBOLS) //読み込み以外の文字が来た時の処理
    //     print_error("Some words are not loaded in the map\n");
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

// void    start_loop(t_data *data)
// {

// }