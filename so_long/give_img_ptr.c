/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_img_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:23:36 by qijin             #+#    #+#             */
/*   Updated: 2026/03/07 17:23:37 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*wall(t_game *game)
{
	return (game->img_wall);
}

void	*fl(t_game *game)
{
	return (game->img_floor);
}

void	*player(t_game *game)
{
	return (game->img_player);
}

void	*collect(t_game *game)
{
	return (game->img_collect);
}

void	*ex(t_game *game)
{
	return (game->img_exit);
}
