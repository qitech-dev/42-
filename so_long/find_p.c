/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:27:58 by qijin             #+#    #+#             */
/*   Updated: 2026/03/16 20:28:00 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	*help_find_p(char **map, int *coordinate)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				coordinate[0] = x;
				coordinate[1] = y;
				return (coordinate);
			}
			x++;
		}
		y++;
	}
	return (coordinate);
}

int	*find_p(char **map)
{
	int	*coordinate;

	coordinate = malloc(2 * sizeof(int));
	if (!coordinate)
		return (NULL);
	coordinate = help_find_p(map, coordinate);
	if (!coordinate)
		return (free(coordinate), NULL);
	return (coordinate);
}
