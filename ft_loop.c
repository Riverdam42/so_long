/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:09:47 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/22 18:23:50 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//animationをループで描写していく！

static void loop_drew()
{
    int count;

    count = 0;
    mlx_destroy_image(data->mlx, data->image.player);
    data->image.player = mlx_xpm_file_to_image(data->mlx, )
}