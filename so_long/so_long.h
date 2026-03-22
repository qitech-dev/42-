/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:14:48 by qijin             #+#    #+#             */
/*   Updated: 2026/03/02 20:14:49 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# define TILE_SIZE	32
# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_UP		65362
# define KEY_LEFT	65361
# define KEY_DOWN	65364
# define KEY_RIGHT	65363

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_w;
	int		map_h;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	int		p_x;
	int		p_y;
	int		moves;
	int		collectibles;
	int		collected;
}	t_game;

void	free_map(char **map);
void	error_exit(char *msg, char **map);
void	init_game_struct(t_game *game);
char	**get_map(char *filename);
int		*find_p(char **map);
int		check_extension(char *filename);
void	flood_fill(char **map, int x, int y, int *dimensions);
int		check_valid_path(char **map, int width, int height);
int		check_characters(t_game *game);
void	validate_map(char **map, t_game *game);
int		close_game(t_game *game);
void	init_window(t_game *game);
char	*wallnm(void);
char	*floornm(void);
char	*playernm(void);
char	*colnm(void);
char	*exitnm(void);
void	*wall(t_game *game);
void	*fl(t_game *game);
void	*player(t_game *game);
void	*collect(t_game *game);
void	*ex(t_game *game);
void	load_images(t_game *game);
void	put_background_to_tile(t_game *game, int x, int y);
void	put_object_to_tile(t_game *game, int x, int y);
void	render_map(t_game *game);
int		key_press(int keycode, t_game *game);

#endif