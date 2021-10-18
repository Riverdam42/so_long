/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:29:16 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/17 10:31:32 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	int	sign;

	sign = 1;
	if (nb < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	if (nb <= -10 || 10 <= nb)
	{
		ft_putnbr_fd(nb / 10 * sign, fd);
	}
	ft_putchar_fd(nb % 10 * sign + '0', fd);
}