/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:44:21 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/21 16:38:49 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	map_image_init(t_data *data)
// {
// 	data->map = 0;
// 	data->mlx = 0;
// 	data->mlx_win = 0;
// 	data->img.player = 0;
// 	data->img.freespace = 0;
// 	data->img.wall = 0;
// 	data->img.collection = 0;
// 	data->img.goal = 0;
// }

static void add_next_newline(t_data *data, char *new_line)
{
	char **new_map; //new_map = {new_line, NULL}
	int		i;

	new_map = (char **)malloc(sizeof(char *) * (data->map_height + 2)); //new_line + NULL //current size + 1
	//if (!new_map)
		//ERROR
	i = 0;
	while(data->map[i])
		new_map[i++] = data->map[i++]; //new_mapに格納されたアドレスをコピーする
	free(data->map);     // free old map
	data->map = new_map;
	data->map_height++;
}

void	ft_read_map(t_data *data, char *map_ber)
{
	int		fd;
	char	*new_line;

	data->map = (char **)malloc(sizeof(char *));
	if (!data->map)
		exit(EXIT_FAILURE);
	data->map[0] = NULL;
	data->map_height = 0;
	fd = open(map_ber, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	new_line = "start";
	while (new_line)
	{
		new_line = get_next_line(fd); //GNLで１行ずつ読み込む //成功したらマップの全行をnew_mapにコピーする
		if (new_line)
	 		add_next_newline(data, new_line);
	}
	//mapを閉じたら（1番最後に）読み込んだnew_lineをフリーする
}

// map = {NULL}
// new_map = {new_line, NULL}

// read map
// map size に応じてwindow を作る

// 5 x 5
// 32
// window ((5 * 32), (5 * 32))
// blue background (160, 160)
