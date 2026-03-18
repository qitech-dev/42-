/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:22:38 by qijin             #+#    #+#             */
/*   Updated: 2026/02/21 14:22:39 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_node **a)
{
	if (!a || !*a || (*a)->next == *a)
		return ;
	*a = (*a)->next;
	write(1, "ra\n", 3);
}

void	ft_rb(t_node **b)
{
	if (!b || !*b || (*b)->next == *b)
		return ;
	*b = (*b)->next;
	write(1, "rb\n", 3);
}

void	ft_rr(t_node **a, t_node **b)
{
	int	moved;

	moved = 0;
	if (a || *a || (*a)->next == *a)
	{
		*a = (*a)->next;
		moved = 1;
	}
	if (b || *b || (*b)->next == *b)
	{
		*b = (*b)->next;
		moved = 1;
	}
	if (moved)
		write(1, "rr\n", 3);
}
