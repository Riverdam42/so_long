/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:44:33 by kkawano           #+#    #+#             */
/*   Updated: 2021/11/06 10:38:05 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sysexits.h>
# include "gnl/get_next_line.h"

# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

# define PLAYER 'P'
# define COLLECT 'C'
# define GOAL 'E'
# define GROUND '0'
# define WALL '1'
# define TILESIZE 32

# define MAP_SYMBOLS "01CEP\n"

typedef struct s_img
{
	void	*player;
	void	*ground;
	void	*wall;
	void	*collect;
	void	*goal;
}				t_img;

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
	int		map_row_count;
	int		map_col_count;
	int		player_x;
	int		player_y;
	int		player_num;
	int		goal_num;
	int		counter;
	int		goal_flag;
	t_img	img;
}				t_data;

void	ft_read_map(t_data *data, char *map_ber);
int		ft_check_map(t_data *data);
void	init_data(t_data *data);
void	set_map_path(t_data *data);
int		ft_draw_map(t_data *data);
int		ft_key_hook(int keycode, t_data *data);
int		ft_close_map(int keycode, t_data *data);
void	print_error(char *str);
void	safe_free(char **str);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
#endif
