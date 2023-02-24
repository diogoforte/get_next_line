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

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		if (fd > 0 && fd < FOPEN_MAX)
			while (buf[fd][i])
				buf[fd][i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (*(buf[fd]) || read(fd, buf[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buf[fd]);
		if (nl(buf[fd]) != 0)
			break ;
	}
	return (line);
}

/* int main()
{
	int a = 1;
	int fd = 0;
	int fd2 = 0;
	int fd3 = 0;
	char *line;
	char *line2;
	char *line3;
	fd = open("/home/diogo/Desktop/get_next_line/fd.txt", O_RDONLY);
	fd2 = open("/home/diogo/Desktop/get_next_line/fd2.txt", O_RDONLY);
	fd3 = open("/home/diogo/Desktop/get_next_line/fd3.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
		if (line == NULL && line2 == NULL && line3 == NULL)
			break;
		if (line != NULL)
			printf("line %d: %s\n", a, line);
		if (line2 != NULL)
			printf("line2 %d: %s\n", a, line2);
		if (line3 != NULL)
			printf("line3 %d: %s\n", a, line3);
		a++;
		free(line);
		free(line2);
		free(line3);
	}
	printf("\nfd = %d", fd);
	printf("\nfd2 = %d", fd2);
	printf("\nfd3 = %d", fd3);
	free(line);
	close(fd);
	return (0);
} */