/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fuctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:29:09 by qijin             #+#    #+#             */
/*   Updated: 2026/03/02 20:29:10 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *filename)
{
	int	size;

	if (!filename)
		return (0);
	size = ft_strlen(filename);
	if (size <= 4)
		return (0);
	if (ft_strncmp(filename + size - 4, ".ber", 4) != 0)
		return (0);
	if (filename[size - 5] == '/')
		return (0);
	return (1);
}

int	check_rectengle(char **map)
{
	int	width;
	int	i;

	i = 0;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	validate_map(char **map, t_game *game)
{
	int	width;
	int	height;

	if (!map || !map[0])
		error_exit("Map is empty or file can not be read.", map);
	if (!check_rectengle(map))
		error_exit("Map is not rectangular.", map);
	if (!check_characters(game))
		error_exit("Invalid characters or wrong amount of P/E/C.", map);
	if (!check_walls(map))
		error_exit("Map is not surrounded by walls.", map);
	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	if (!check_valid_path(map, width, height))
		error_exit("There is not a valid path in map.", map);
}
