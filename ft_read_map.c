/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 05:15:37 by kkawano           #+#    #+#             */
/*   Updated: 2021/11/06 06:43:55 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_square(t_data *data, char *new_line)
{
	int	row_length;

	row_length = ft_strlen(new_line);
	if (ft_strchr(new_line, '\n'))
		row_length -= 1;
	if (row_length != data->map_col_count)
		print_error("The map is not square\n");
}

static void	add_next_newline(t_data *data, char *new_line)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(sizeof(char *) * (data->map_row_count + 2));
	if (!new_map)
		print_error("malloc error!!\n");
	i = 0;
	while (data->map[i])
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

static void	map_init(t_data *data)
{
	data->map[0] = NULL;
	data->map_row_count = 0;
	data->map_col_count = 0;
}

static void	check_map_name(char *map_ber)
{
	size_t	name_len;
	size_t	result;

	name_len = 0;
	name_len = ft_strlen(map_ber);
	result = ft_strncmp(&map_ber[name_len - 4], ".ber", 4);
	if (result != 0)
		print_error("The extension of the map is different\n");
}

void	ft_read_map(t_data *data, char *map_ber)
{
	int		fd;
	char	*new_line;

	check_map_name(map_ber);
	data->map = (char **)malloc(sizeof(char *));
	if (!data->map)
		print_error("malloc error!!\n");
	map_init(data);
	fd = open(map_ber, O_RDONLY);
	if (fd == -1)
		print_error("open failed!!\n");
	new_line = get_next_line(fd);
	data->map_col_count = (ft_strlen(new_line) - 1);
	while (new_line)
	{
		if (new_line)
		{
			check_square(data, new_line);
			add_next_newline(data, new_line);
		}
		new_line = get_next_line(fd);
	}
	ft_check_map(data);
}
