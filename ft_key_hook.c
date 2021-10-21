/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:19:40 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/21 22:37:45 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_data *data) //特定のkeycode(a==0)を押したら主人公を動かして歩数をカウントする
{
	printf("counter: %d\n", data->counter++);
	if (keycode == 0) //a
		data->player_x -= 32;
	if (keycode == 1) //s
		data->player_y += 32;
	if (keycode == 2) //d
		data->player_x += 32;
	if (keycode == 13) //w
		data->player_y -= 32;
	if (keycode == 53) //esc
	{
        mlx_destroy_window(data->mlx, data->win);
        exit(EXIT_SUCCESS);
    }
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img.player, data->player_x, data->player_y);
    return (0);
}