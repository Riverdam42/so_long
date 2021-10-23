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

# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

# define PLAYER 'P'
# define COLLECTION 'C'
# define GOAL 'E'
# define FREESPACE '0'
# define WALL '1'
# define TILESIZE 32

typedef struct s_img
{
	void	*player;
	void	*freespace;
	void	*wall;
	void	*collection;
	void	*goal;
}				t_img;


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
	void	*win;
	int		img_width; //画像の幅
	int		img_height; //画像の高さ
	int		bits_per_pixel;
	int		line_length;
	int		map_row_count;
	int		map_col_count;
	int		endian;
	int		player_x;
	int		player_y;
	int		counter;
	int		goal_flag;
	t_img	img;
}				t_data;

void	ft_read_map(t_data *data, char *map_ber);
void	init_data(t_data *data);
void	set_map_path(t_data *data);
int		ft_draw_map(t_data *data);
int		ft_key_hook(int keycode, t_data *data);
int		ft_close_map(int keycode, t_data *data);
int		stop_and_exit(t_data *data);
int		print_error(char *str);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
#endif