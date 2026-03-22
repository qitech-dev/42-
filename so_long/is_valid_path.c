/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:19:49 by qijin             #+#    #+#             */
/*   Updated: 2026/03/05 18:19:50 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
	int		y;
	int		height;
	char	**copy;

	if (!map || !map[0])
		return (NULL);
	height = 0;
	while (map[height])
		height++;
	copy = malloc((height + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < height)
	{
		copy[y] = ft_strdup(map[y]);
		if (!copy[y])
		{
			free_map(copy);
			return (NULL);
		}
		y++;
	}
	copy[height] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y, int *dimensions)
{
	int	width;
	int	height;

	width = dimensions[0];
	height = dimensions[1];
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, dimensions);
	flood_fill(map, x - 1, y, dimensions);
	flood_fill(map, x, y + 1, dimensions);
	flood_fill(map, x, y - 1, dimensions);
}

int	check_is_still_c_e(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_valid_path(char **map, int width, int height)
{
	char	**map_copy;
	int		*coordinate;
	int		dimensions[2];

	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	coordinate = find_p(map);
	if (!coordinate)
		return (0);
	dimensions[0] = width;
	dimensions[1] = height;
	flood_fill(map_copy, coordinate[0], coordinate[1], dimensions);
	free(coordinate);
	if (!check_is_still_c_e(map_copy))
	{
		free_map(map_copy);
		return (0);
	}
	free_map(map_copy);
	return (1);
}
