/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:46:27 by dinunes-          #+#    #+#             */
/*   Updated: 2022/11/27 11:46:27 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *line;
	static char buf[BUFFER_SIZE + 1];
	int i;

	i = 0;
	line = NULL;
	while (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		while(buf[i])
		{
			buf[i] = 0;
			i++;
		}
		return (NULL);
	}
	while (read(fd, buf, BUFFER_SIZE) > 0 && *buf)
	{
		line = ft_strjoin(line, buf);
		if (nl(buf) != -1)
			{
				break ;
			}
	}
	return (line);
}

/* 
int main()
{
	int i = 1;
	int fd = 0;
	char *line;
	fd = open("./test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("line %d: %s", i, line);
		i++;
	}
	printf("\nfd = %d", fd);
	free(line);
	close(fd);
	return (0);
} */