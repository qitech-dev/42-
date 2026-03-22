/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:40:20 by qijin             #+#    #+#             */
/*   Updated: 2026/03/02 20:40:22 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map_height(char *filename)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		height++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (height);
}

//To avoid interfering with subsequent length calculations
static void	delete_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static char	**read_map(int fd, char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (free_map(map), close(fd), NULL);
		delete_newline(map[i]);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**get_map(char *filename)
{
	char	**map;
	int		height;
	int		fd;

	height = get_map_height(filename);
	if (height < 0)
		return (NULL);
	if (height == 0)
	{
		errno = 0;
		return (NULL);
	}
	map = (char **)malloc((height + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free_map(map), NULL);
	map = read_map(fd, map, height);
	return (map);
}
