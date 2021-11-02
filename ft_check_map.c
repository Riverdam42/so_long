/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:34:40 by kkawano           #+#    #+#             */
/*   Updated: 2021/11/02 15:07:14 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int     ft_check_map(t_data *data)
{
	int x;
	int y;

	y = -1;
	while(++y < data->map_row_count)
	{
		x = -1;
		while (++x < data->map_col_count)
		{
			if (data->map[y][x] == 'C')
				data->goal_flag++;
			if (data->map[y][x] == 'P')
				data->player_num++;
			if (!(ft_strchr(MAP_SYMBOLS, data->map[y][x])))
				print_error("ERROR : Some words are not loaded in the map\n");
		}
	}
	if (data->player_num != 1)
		print_error("ERROR : There are too many players\n");
	return (0);
}
