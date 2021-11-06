/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:34:40 by kkawano           #+#    #+#             */
/*   Updated: 2021/11/06 21:11:25 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_char(t_data *data)
{
	if (data->player_num != 1)
		print_error("There should be only one player on the map!!\n");
	if (data->goal_num < 1)
		print_error("There should be at least one goal on the map!!\n");
	if (data->goal_flag < 1)
		print_error("There should be at least one collectible on the map!!\n");
}

int	ft_check_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map_row_count)
	{
		x = -1;
		while (++x < data->map_col_count)
		{
			if (y == 0 || y == data->map_row_count - 1 || x == 0 \
					|| x == data->map_col_count - 1)
				if (data->map[y][x] != WALL)
					print_error("It's not surrounded by walls!!\n");
			if (data->map[y][x] == 'C')
				data->goal_flag++;
			if (data->map[y][x] == 'P')
				data->player_num++;
			if (data->map[y][x] == 'E')
				data->goal_num++;
			if (!(ft_strchr(MAP_SYMBOLS, data->map[y][x])))
				print_error("Some words are not loaded in the map!!\n");
		}
	}
	check_char(data);
	return (0);
}
