/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stop_to_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:17:09 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/17 10:21:51 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_destroy(t_vars *vars)
{
	if (vars->img.player)
		mlx_destroy_image(vars->mlx, vars->img.player);
	if (vars->img.freespace)
		mlx_destroy_image(vars->mlx, vars->img.freespace);
	if (vars->img.wall)
		mlx_destroy_image(vars->mlx, vars->img.wall);
	if (vars->img.collection)
		mlx_destroy_image(vars->mlx, vars->img.collection);
	if (vars->img.goal)
		mlx_destroy_image(vars->mlx, vars->img.goal);
}

int	destroy_and_exit(t_vars *vars)
{
	int	i;

	i = -1;
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	img_destroy(vars);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->map)
	{
		while (vars->map[++i])
			free(vars->map[i]);
		free(vars->map);
	}
	exit(EXIT_SUCCESS);
	return (0);
}