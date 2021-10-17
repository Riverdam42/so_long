/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:44:21 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/17 10:15:02 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//readでmapを読み込んでいく

static void	img_init(t_vars *vars)
{
	vars->map = NULL;
	vars->mlx = NULL;
	vars->mlx_win = NULL;
	vars->img.player = NULL;
	vars->img.freespace = NULL;
	vars->img.wall = NULL;
	vars->img.collection = NULL;
	vars->img.goal = NULL;
}