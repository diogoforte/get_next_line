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
	while (str[i] && str[i] != '\n')
		i++;
	return ((i + (str[i] == '\n')));
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*ret;
	size_t	i;

	ret = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (str1 && str1[++i])
		ret[i] = str1[i];
	i += (!str1);
	while (*str2)
	{
		ret[i++] = *str2;
		if (*str2++ == '\n')
			break ;
	}
	ret[i] = 0;
	free (str1);
	return (ret);
}

int	nl(char *line)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (line[++i])
	{
		if (line[i] == 10)
		{
			line[i++] = 0;
			j = 0;
			break ;
		}
		line[i] = 0;
	}
	if (j == 0)
	{
		while (line[i])
		{
			line[j++] = line[i];
			line[i++] = 0;
		}
	}
	return (j);
}
