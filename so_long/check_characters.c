/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:08:46 by qijin             #+#    #+#             */
/*   Updated: 2026/03/16 20:08:48 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	help_check_char(t_game *game, int *e, int *p, int *c)
{
	int		y;
	int		x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				(*e)++;
			else if (game->map[y][x] == 'P')
				(*p)++;
			else if (game->map[y][x] == 'C')
			{
				(*c)++;
				game->collectibles++;
			}
			else if (game->map[y][x] != '0' && game->map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_characters(t_game *game)
{
	int	e;
	int	p;
	int	c;

	e = 0;
	p = 0;
	c = 0;
	if (!help_check_char(game, &e, &p, &c))
		return (0);
	return (e == 1 && p == 1 && c >= 1);
}
