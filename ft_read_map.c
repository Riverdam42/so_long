/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:44:21 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/22 19:00:02 by kkawano          ###   ########.fr       */
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

void	set_map_path(t_data *data)
{
	data->img.player = mlx_xpm_file_to_image(data->mlx, "image/kirby.xpm",
			&data->img_width, &data->img_low);
	// if (!data->img.player)
		//print_errr(読み込めないよ！のERROR)
	data->img.freespace = mlx_xpm_file_to_image(data->mlx, "image/freespace.xpm",
			&data->img_width, &data->img_low);
	data->img.wall = mlx_xpm_file_to_image(data->mlx,"image/starblock.xpm",
			&data->img_width, &data->img_low);
	data->img.collection = mlx_xpm_file_to_image(data->mlx, "image/Maximum.xpm",
			&data->img_width, &data->img_low);
	data->img.goal = mlx_xpm_file_to_image(data->mlx, "image/Star.xpm",
			&data->img_width, &data->img_low);
}

static void add_next_newline(t_data *data, char *new_line)
{
	char **new_map; //new_map = {new_line, NULL}
	int		i;

	new_map = (char **)malloc(sizeof(char *) * (data->map_low + 2));
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
	data->map_low++;
}

void	ft_read_map(t_data *data, char *map_ber)
{
	int		fd;
	char	*new_line;

	data->map = (char **)malloc(sizeof(char *));
	if (!data->map)
		exit(EXIT_FAILURE);
	data->map[0] = NULL;
	data->map_low = 0;
	fd = open(map_ber, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	new_line = "start";
	while (new_line)
	{
		new_line = get_next_line(fd); //GNLで１行ずつ読み込む //成功したらマップの全行をnew_mapにコピーする
		if (new_line)
			data->map_low = ft_stelen(new_line);
	 		add_next_newline(data, new_line);
	}
	//mapを閉じたら（1番最後に）読み込んだnew_lineをフリーする
}

// read map
// map size に応じてwindow を作る