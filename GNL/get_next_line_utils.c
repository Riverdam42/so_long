/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:33:19 by kkawano           #+#    #+#             */
/*   Updated: 2021/09/02 15:26:52 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t	n)
{
	char	*new_str;
	size_t	len1;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(s1);
	new_str = malloc(sizeof(char) * ((len1 + n) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	if (s1 != NULL)
	{
		while (s1[i])
		{
			new_str[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j] && n--)
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char )c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strchr_len(const char *s, char c)
{
	size_t			byte;

	byte = 0;
	while (s[byte])
	{
		if (s[byte] == (char) c)
			return (byte);
		byte++;
	}
	return (byte);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}
