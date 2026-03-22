/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:28:40 by qijin             #+#    #+#             */
/*   Updated: 2026/03/07 16:28:42 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*wallnm(void)
{
	return ("./textures/wall.xpm");
}

char	*floornm(void)
{
	return ("./textures/floor.xpm");
}

char	*playernm(void)
{
	return ("./textures/player.xpm");
}

char	*colnm(void)
{
	return ("./textures/collectible.xpm");
}

char	*exitnm(void)
{
	return ("./textures/exit.xpm");
}
