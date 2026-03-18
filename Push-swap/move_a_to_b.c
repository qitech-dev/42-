/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:58:03 by qijin             #+#    #+#             */
/*   Updated: 2026/03/07 15:58:06 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		ft_rr(a, b);
}

static void	reverse_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		ft_rrr(a, b);
}

static void	finish_rotation_a(t_node **a, t_node *top_node, int is_half_top)
{
	while (*a != top_node)
	{
		if (is_half_top)
			ft_ra(a);
		else
			ft_rra(a);
	}
}

static void	finish_rotation_b(t_node **b, t_node *top_node, int is_half_top)
{
	while (*b != top_node)
	{
		if (is_half_top)
			ft_rb(b);
		else
			ft_rrb(b);
	}
}

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;
	int		top_a;
	int		top_b;

	cheapest_node = get_cheapest_node(*a);
	top_a = 0;
	if (cheapest_node->current_pos <= (get_stack_size(*a) / 2))
		top_a = 1;
	top_b = 0;
	if (cheapest_node->target_node->current_pos <= (get_stack_size(*b) / 2))
		top_b = 1;
	if (top_a && top_b)
		rotate_both(a, b, cheapest_node);
	else if (!top_a && !top_b)
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation_a(a, cheapest_node, top_a);
	finish_rotation_b(b, cheapest_node->target_node, top_b);
	ft_pb(b, a);
}
