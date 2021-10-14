/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:44:33 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/14 22:53:1 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
#include <sysexits.h>
#include "gnl/get_next_line.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		player_x;
	int		player_y;
	int		counter;
}				t_data;

int	ft_key_hook(int keycode, t_data *data);
int	ft_close(int keycode, t_data *data);
#endif