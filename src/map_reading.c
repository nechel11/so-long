/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zafar <nbyrd@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:14:09 by zafar             #+#    #+#             */
/*   Updated: 2022/01/21 13:29:05 by zafar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	line_counter(char *file)
{
	int		linecount;
	int		fd;
	int		readcount;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 0;
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

static int	line_cheq(char **map, char *file)
{
	int	i;
	int	line;

	i = 0;
	line = line_counter(file);
	while (map[i])
		i++;
	if (i == line)
		return (1);
	return (0);
}

static void	err(int i)
{
	(void)i;
	printf("Bad map\n");
	exit(0);
}

static void	cheq(char **map, char *file)
{
	if (line_cheq(map, file) == 0)
		err(1);
}

char	**map_reading(char *file)
{
	int		fd;
	char	*line;
	char	**map;
	char	*map_sep;
	char	*sep;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_sep = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		sep = map_sep;
		map_sep = ft_strjoin(sep, line);
		free(line);
		free(sep);
	}
	map = ft_split(map_sep, '\n');
	free(map_sep);
	close(fd);
	cheq(map, file);
	return (map);
}
