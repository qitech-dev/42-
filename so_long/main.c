/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:19:42 by qijin             #+#    #+#             */
/*   Updated: 2026/03/04 14:19:48 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_window(t_game game)
{
	init_window(&game);
	load_images(&game);
	render_map(&game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_loop(game.mlx);
}

static void	handle_error_map(void)
{
	if (errno == ENOENT)
		error_exit("No exist map", NULL);
	if (errno == EACCES)
		error_exit("Permission denied", NULL);
	error_exit("Map is empty or file can not be read.", NULL);
}

static void	validate_and_setup_map(t_game *game)
{
	validate_map(game->map, game);
	if (game->map && game->map[0])
	{
		game->map_w = ft_strlen(game->map[0]);
		game->map_h = 0;
		while (game->map[game->map_h])
			game->map_h++;
	}
}

static int	process_arguments(int argc, char **argv, t_game *game)
{
	char	*filename;

	if (argc != 2)
	{
		write(2, "Error\nUsage: ./so_long <map_file.ber>\n", 38);
		return (1);
	}
	init_game_struct(game);
	filename = argv[1];
	if (!check_extension(filename))
		error_exit("The filename is not end by .ber.", game->map);
	game->map = get_map(filename);
	if (!game->map)
		handle_error_map();
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (process_arguments(argc, argv, &game) != 0)
		return (1);
	validate_and_setup_map(&game);
	load_window(game);
	return (0);
}
