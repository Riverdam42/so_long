/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:44:21 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/23 02:02:15 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map_path(t_data *data)
{
	data->img.player = mlx_xpm_file_to_image(data->mlx, "image/kirby.xpm",
			&data->img_width, &data->img_height);
	// if (!data->img.player)
		//print_errr(読み込めないよ！のERROR)
	data->img.freespace = mlx_xpm_file_to_image(data->mlx, "image/freespace.xpm",
			&data->img_width, &data->img_height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx,"image/starblock.xpm",
			&data->img_width, &data->img_height);
	data->img.collection = mlx_xpm_file_to_image(data->mlx, "image/Maximum.xpm",
			&data->img_width, &data->img_height);
	data->img.goal = mlx_xpm_file_to_image(data->mlx, "image/Star.xpm",
			&data->img_width, &data->img_height);
}

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
		exit(EXIT_FAILURE);
	data->map[0] = NULL;
	data->map_row_count = 0;
	data->map_col_count = 0;
	fd = open(map_ber, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	new_line = "start";
	while (new_line)
	{
		new_line = get_next_line(fd); //GNLで１行ずつ読み込む //成功したらマップの全行をnew_mapにコピーする
		if (new_line)
		{
			add_next_newline(data, new_line);
			if (data->map_col_count == 0)
			data->map_col_count = (ft_strlen(new_line) - 1);
		}
	}
	//mapを閉じたら（1番最後に）読み込んだnew_lineをフリーする
}

// read map
// map size に応じてwindow を作る