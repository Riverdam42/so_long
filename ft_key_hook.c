/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:19:40 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/28 15:42:06 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wall_and_move_player(t_data *data, int move_x, int move_y)
{
	if (data->map[data->player_y + move_y][data->player_x + move_x] == WALL)
	{
		return (0);
	}
	if (data->map[data->player_y + move_y][data->player_x + move_x] == COLLECTION)
		data->goal_flag--;
	if (data->map[data->player_y + move_y][data->player_x + move_x] == GOAL)
	{
		//goal!!!
		if (data->goal_flag == 0)
			exit(EXIT_SUCCESS);
		return (0);
	}
	data->map[data->player_y + move_y][data->player_x + move_x] = PLAYER;
	data->map[data->player_y][data->player_x] = FREESPACE;
	data->player_x += move_x;
	data->player_y += move_y;
	return (1);
}

int	ft_key_hook(int keycode, t_data *data)
{
	int result;

	result = 0;

	if (keycode == A_KEY)
			result = check_wall_and_move_player(data, -1, 0);
	if (keycode == S_KEY)
			result = check_wall_and_move_player(data, 0, 1);
	if (keycode == D_KEY)
			result = check_wall_and_move_player(data, 1, 0);
	if (keycode == W_KEY)
			result = check_wall_and_move_player(data, 0, -1);
	if (keycode == ESC_KEY)
	{
        mlx_destroy_window(data->mlx, data->win);
        exit(EXIT_SUCCESS);
    }
	mlx_clear_window(data->mlx, data->win);
    if (result != 0)
		printf("counter: %d\n", data->counter++);
	ft_draw_map(data);
	return (0);
}