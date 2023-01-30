/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:46:23 by dinunes-          #+#    #+#             */
/*   Updated: 2022/11/27 11:46:23 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != 10)
		i++;
	if (str[i] == 10)
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*ret;
	size_t	i;

	ret = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (str1 && str1[i])
	{
		ret[i] = str1[i];
		i++;
	}
	free(str1);
	while (*str2)
	{
		ret[i++] = *str2;
		if (*str2++ == 10)
			break ;
	}
	ret[i] = 0;
	return (ret);
}

int	nl(char *buf)
{
	int	i;
	int	g;
	int	j;

	i = 0;
	g = 0;
	j = 0;
	while (buf[i])
	{
		if (j == 1)
			buf[g++] = buf[i];
		if (buf[i] == 10)
			j = 1;
		buf[i++] = 0;
	}
	return (j);
}
