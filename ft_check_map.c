/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:34:40 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/30 16:27:33 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void check_map(t_data *data, char *new_line)
{
	int i;

	i = 0;
	while (new_line[i])
	{
		if (new_line[i] == 'C')
				data->goal_flag++;
		if (!ft_strchr(MAP_SYMBOLS, new_line[i]))
				print_error("ERROR : Some words are not loaded in the map\n");
		i++;
	}
	printf("player_num : %d\n", data->player_num);
	if (data->player_num != 1)
		print_error("ERROR : There are too many players\n");
}
