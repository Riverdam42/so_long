/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:19:40 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/23 00:59:09 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_data *data) //特定のkeycode(a==0)を押したら主人公を動かして歩数をカウントする
{
	printf("counter: %d\n", data->counter++);
	if (keycode == A_KEY)
		//if (data->map[x - 32][y] != WALL) //移動した先がWALLじゃなかったら移動する
			data->player_x -= 32;
	if (keycode == S_KEY)
		data->player_y += 32;
	if (keycode == D_KEY)
		data->player_x += 32;
	if (keycode == W_KEY)
		data->player_y -= 32;
	if (keycode == ESC_KEY)
	{
        mlx_destroy_window(data->mlx, data->win);
        exit(EXIT_SUCCESS);
    }
	mlx_clear_window(data->mlx, data->win);
    return (0);
}