/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:19:40 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/22 16:01:08 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_data *data) //特定のkeycode(a==0)を押したら主人公を動かして歩数をカウントする
{
	printf("counter: %d\n", data->counter++);
	if (keycode == A)
		data->player_x -= 32;
	if (keycode == S)
		data->player_y += 32;
	if (keycode == D)
		data->player_x += 32;
	if (keycode == W)
		data->player_y -= 32;
	if (keycode == ESC)
	{
        mlx_destroy_window(data->mlx, data->win);
        exit(EXIT_SUCCESS);
    }
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img.player, data->player_x, data->player_y);
    return (0);
}