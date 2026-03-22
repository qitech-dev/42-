/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:55:00 by qijin             #+#    #+#             */
/*   Updated: 2026/03/08 17:55:01 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_position(t_game *game, int n_x, int n_y)
{	
	game->map[n_y][n_x] = 'P';
	game->p_x = n_x;
	game->p_y = n_y;
	put_background_to_tile(game, n_x, n_y);
	put_object_to_tile(game, n_x, n_y);
	game->moves++;
}

static void	help_move_player(t_game *game)
{
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	ft_printf("YOU WIN!!!\n");
	close_game(game);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	char	target;
	int		old_x;
	int		old_y;

	if (new_x < 0 || new_y < 0 || new_x >= game->map_w || new_y >= game->map_h)
		return ;
	target = game->map[new_y][new_x];
	old_x = game->p_x;
	old_y = game->p_y;
	if (target == '1')
		return ;
	if (target == 'E')
	{
		if (game->collected == game->collectibles)
			help_move_player(game);
		return ;
	}
	if (target == 'C')
		game->collected++;
	update_position(game, new_x, new_y);
	game->map[old_y][old_x] = '0';
	put_background_to_tile(game, old_x, old_y);
	ft_printf("Moves: %d\n", game->moves);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, game->p_x, game->p_y - 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, game->p_x - 1, game->p_y);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, game->p_x, game->p_y + 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, game->p_x + 1, game->p_y);
	return (0);
}
