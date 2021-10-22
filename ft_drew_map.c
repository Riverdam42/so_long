/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drew_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:46:17 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/22 17:01:37 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_drew_map(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data.mlx, data.win, data.img.player, 5, 5);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data.mlx, data.win, data.img.collection, 5, 5);
	else if (data->map[y][x] == 'E')
        mlx_put_image_to_window(data.mlx, data.win, data.img.goal, 5, 5);
	else if (data->map[y][x] == '0')
        mlx_put_image_to_window(data.mlx, data.win, data.img.freespace, 5, 5);
    else if (data->map[y][x] == '1')
        mlx_put_image_to_window(data.mlx, data.win, data.img.wall, 5, 5);
    // else
    //     print_error("マップに読み込めない記号がありまっせ");
}