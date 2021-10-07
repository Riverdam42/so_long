/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:33:12 by kkawano           #+#    #+#             */
/*   Updated: 2021/09/04 22:44:32 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	safe_free(char **str, int num)
{
	if (*str != NULL)
	{
		free (*str);
		*str = (NULL);
	}
	return (num);
}

static	int	find_newline(char **line, char **keep, char *buf)
{
	char	*tmp;
	char	*tmp1;
	size_t	enter_len;

	enter_len = ft_strchr_len(buf, '\n');
	tmp = ft_strnjoin(*line, buf, enter_len + 1);
	safe_free(line, 0);
	if (!tmp)
		return (-1);
	*line = tmp;
	if (buf[enter_len] == '\0')
		safe_free(keep, 0);
	else
	{
		tmp1 = ft_strdup(buf + enter_len + 1);
		safe_free(keep, 0);
		if (!tmp1)
			return (-1);
		*keep = tmp1;
	}
	return (1);
}

static	int	judge_fd(int fd, char **line, char **keep)
{
	char		*buf;
	int			flag;
	ssize_t		read_size;

	read_size = 1;
	flag = 1;
	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	while (read_size >= 1 && flag == 1 && !(ft_strchr(*line, '\n')))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		if (read_size == -1)
			return (safe_free(&buf, -1));
		if (read_size == 0)
			return (safe_free(&buf, 0));
		flag = find_newline(line, keep, buf);
	}
	return (safe_free(&buf, 1));
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*line;
	int			read_fd;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_strdup("");
	if (!line)
		return (NULL);
	if (keep != NULL)
		find_newline(&line, &keep, keep);
	read_fd = judge_fd(fd, &line, &keep);
	if (read_fd == 0 && *line == '\0')
	{
		safe_free(&line, 0);
		return (NULL);
	}
	else if (read_fd == -1)
	{
		safe_free(&line, 0);
		return (NULL);
	}
	else
		return (line);
}
