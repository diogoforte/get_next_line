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
	int i = 1;
	int fd = 0;
	char *line;
	fd = open("", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("line %d: %s", i, line);
		i++;
		free(line);
	}
	printf("\nfd = %d", fd);
	free(line);
	close(fd);
	return (0);
} */