/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:05:58 by qijin             #+#    #+#             */
/*   Updated: 2026/02/21 14:06:02 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_node **a)
{
	if (!a || !*a || (*a)->next == *a)
		return ;
	*a = (*a)->prev;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_node **b)
{
	if (!b || !*b || (*b)->next == *b)
		return ;
	*b = (*b)->prev;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_node **a, t_node **b)
{
	int	moved;

	moved = 0;
	if (a || *a || (*a)->next == *a)
	{
		*a = (*a)->prev;
		moved = 1;
	}
	if (b || *b || (*b)->next == *b)
	{
		*b = (*b)->prev;
		moved = 1;
	}
	if (moved)
		write(1, "rrr\n", 4);
}
