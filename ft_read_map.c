/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:44:21 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/28 15:42:39 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void add_next_newline(t_data *data, char *new_line)
{
	char **new_map; //new_map = {new_line, NULL}
	int		i;

	new_map = (char **)malloc(sizeof(char *) * (data->map_row_count + 2));
	if (!new_map)
		stop_and_exit(data);
	i = 0;
	while(data->map[i])
	{
		new_map[i] = data->map[i];
		i++;
	}
	new_map[i] = new_line;
	new_map[i + 1] = NULL;
	free(data->map);
	data->map = new_map;
	data->map_row_count++;
}

void	ft_read_map(t_data *data, char *map_ber)
{
	int		fd;
	char	*new_line;

	data->map = (char **)malloc(sizeof(char *));
	if (!data->map)
		print_error("ERROR : malloc error!!\n");
	data->map[0] = NULL;
	data->map_row_count = 0;
	data->map_col_count = 0;
	fd = open(map_ber, O_RDONLY);
	if (fd == -1)
	{
		print_error("ERROR : open failed!!\n");
	}
	new_line = "start";
	while (new_line)
	{
		new_line = get_next_line(fd); //GNLで１行ずつ読み込む //成功したらマップの全行をnew_mapにコピーする
		if (new_line)
		{
			add_next_newline(data, new_line);
			if (data->map_col_count == 0)
			data->map_col_count = (ft_strlen(new_line) - 1);
			check_map(data, new_line);
		}
		//else
		// 	print_error("ERROR : GNL failed!!\n");
	}
	//mapを閉じたら（1番最後に）読み込んだnew_lineをフリーする
}

// read map
// map size に応じてwindow を作る