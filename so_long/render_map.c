/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:24:01 by qijin             #+#    #+#             */
/*   Updated: 2026/03/06 16:24:02 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, wallnm(), &w, &h);
	if (!game->img_wall)
		error_exit("Failed to load wall texture", game->map);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, floornm(), &w, &h);
	if (!game->img_floor)
		error_exit("Failed to load floor texture", game->map);
	game->img_player = mlx_xpm_file_to_image(game->mlx, playernm(), &w, &h);
	if (!game->img_player)
		error_exit("Failed to load player texture", game->map);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, colnm(), &w, &h);
	if (!game->img_collect)
		error_exit("Failed to load collectible texture", game->map);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, exitnm(), &w, &h);
	if (!game->img_exit)
		error_exit("Failed to load exit texture", game->map);
}

void	put_background_to_tile(t_game *game, int x, int y)
{
	char	tile;
	int		t_x;
	int		t_y;

	tile = game->map[y][x];
	t_x = x * TILE_SIZE;
	t_y = y * TILE_SIZE;
	if (tile != '1')
		mlx_put_image_to_window(game->mlx, game->win, fl(game), t_x, t_y);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, wall(game), t_x, t_y);
}

void	put_object_to_tile(t_game *game, int x, int y)
{
	char	tile;
	int		t_x;
	int		t_y;

	tile = game->map[y][x];
	t_x = x * TILE_SIZE;
	t_y = y * TILE_SIZE;
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, collect(game), t_x, t_y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, ex(game), t_x, t_y);
	else if (tile == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, player(game), t_x, t_y);
		game->p_x = x;
		game->p_y = y;
	}
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			put_background_to_tile(game, x, y);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			put_object_to_tile(game, x, y);
			x++;
		}
		y++;
	}
}
