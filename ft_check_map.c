/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:34:40 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/26 18:23:38 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

// void chack_map(t_data *data, int x, int y)
// {
//     data->goal_flag = 0;
//     if (data->map[y][x] == 'C')
// 			data->goal_flag++;
//     printf("goal_flag : %d\n", data->goal_flag);
// }

void check_map(t_data *data, char *new_line)
{
	int i;

	i = 0;
	while (new_line[i])
	{
		if (new_line[i] == 'C')
				data->goal_flag++;
		else if (!ft_strchr(MAP_SYMBOLS, new_line[i]))
				print_error("Some words are not loaded in the map\n");
		i++;
	}
}