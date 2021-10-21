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

typedef struct s_img
{
	void	*player;
	void	*freespace;
	void	*wall;
	void	*collection;
	void	*goal;
}				t_img;

// typedef struct s_player
// {
// 	int		x;
// 	int		y;
// }				t_player;

// typedef struct s_point
// {
// 	int	x;
// 	int	y;
// }				t_point;

typedef struct	s_data
{
	char	**map;
	char	*addr;
	void	*mlx;
	void	*img;
	void	*win;
	char	*relative_path;
	int		img_width; //画像の幅
	int		img_height; //画像の高さ
	int		bits_per_pixel;
	int		line_length;
	int		map_height;
	int		endian;
	int		player_x;
	int		player_y;
	int		counter;
	t_img	map_img;
}				t_data;

void	ft_read_map(t_data *data, char *map_ber);
int		ft_key_hook(int keycode, t_data *data);
int		ft_close(int keycode, t_data *data);
int		stop_and_exit(t_data *data);
int		print_error(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
#endif