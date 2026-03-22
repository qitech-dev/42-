/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:56:09 by qijin             #+#    #+#             */
/*   Updated: 2026/03/06 15:56:10 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sz_x(t_game *game)
{
	return (game->map_w * TILE_SIZE);
}

static int	size_y(t_game *game)
{
	return (game->map_h * TILE_SIZE);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Failed to initialize MLX", game->map);
	game->win = mlx_new_window(game->mlx, sz_x(game), size_y(game), "so_long");
	if (!game->win)
		error_exit("Failed to create window", game->map);
}
