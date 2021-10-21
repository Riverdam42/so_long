/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stop_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:17:09 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/21 21:39:16 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_destroy(t_data *data)
{
	if (data->img.player)
		mlx_destroy_image(data->mlx, data->img.player);
	if (data->img.freespace)
		mlx_destroy_image(data->mlx, data->img.freespace);
	if (data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (data->img.collection)
		mlx_destroy_image(data->mlx, data->img.collection);
	if (data->img.goal)
		mlx_destroy_image(data->mlx, data->img.goal);
}

int	stop_and_exit(t_data *data)
{
	int	i;

	i = -1;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	img_destroy(data);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
	{
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
	exit(EXIT_SUCCESS);
	return (0);
}