/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:14:18 by kkawano           #+#    #+#             */
/*   Updated: 2021/11/02 15:56:14 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error\n", 6);
	write(2, str, len);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

// void	print(char *str)
// {
// 	size_t	len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	write(1, str, len);
// 	write(1, "\n", 1);
// }

// void safe_free(char **str)
// {
// 	if (*str != NULL)
// 	{
// 		free (*str);
// 		*str = (NULL);
// 	}
// }