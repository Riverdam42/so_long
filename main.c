/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:49:19 by kkawano           #+#    #+#             */
/*   Updated: 2021/11/06 21:49:24 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		print_error("Invalid arguments!!\n");
	}
	init_data(&data);
	ft_read_map(&data, argv[1]);
	init_mlx(&data);
	set_map_path(&data);
	ft_draw_map(&data);
	mlx_key_hook(data.win, ft_key_hook, &data);
	mlx_hook(data.win, 17, 1L << 17, ft_close_map, &data);
	mlx_loop(data.mlx);
	return (0);
}
