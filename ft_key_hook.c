/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:19:40 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/12 18:17:26 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_vars *vars) //特定のkeycode(a==0)を押したら主人公を動かして歩数をカウントする
{
	(void)vars;
	printf("keycode: %d\n", keycode);
	if (keycode == 0)
		printf("You pressed 'a'\n");
	if (keycode == 1)
		printf("You pressed 's'\n");
	if (keycode == 2)
		printf("You pressed 'd'\n");
	if (keycode == 13)
		printf("You pressed 'w'\n");
	if (keycode == 53)
	{
        mlx_destroy_window(vars->mlx, vars->win);
        exit(EXIT_SUCCESS);
    }
    return (0);
}