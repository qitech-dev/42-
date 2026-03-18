/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:11:09 by qijin             #+#    #+#             */
/*   Updated: 2026/02/26 20:11:10 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_to_a(t_node **a, t_node **b)
{
	t_node	*target;
	int		size_a;
	int		is_top_half;

	target = (*b)->target_node;
	size_a = get_stack_size(*a);
	is_top_half = 0;
	if (target->current_pos <= (size_a / 2))
		is_top_half = 1;
	while (*a != target)
	{
		if (is_top_half)
			ft_ra(a);
		else
			ft_rra(a);
	}
	ft_pa(a, b);
}

void	push_a_to_b(t_node **a, t_node **b)
{
	if (get_stack_size(*a) > 3 && !*b)
		ft_pb(b, a);
	if (get_stack_size(*a) > 3 && get_stack_size(*b) == 1)
		ft_pb(b, a);
	while (get_stack_size(*a) > 3)
	{
		set_current_position(*a);
		set_current_position(*b);
		set_target_a(*a, *b);
		calculate_cost_a(*a, *b);
		set_cheapest(*a);
		move_a_to_b(a, b);
	}
}

void	push_b_to_a(t_node **a, t_node **b)
{
	while (*b)
	{
		set_current_position(*a);
		set_current_position(*b);
		set_target_b(*a, *b);
		move_b_to_a(a, b);
	}
}

void	final_rotate(t_node **a)
{
	t_node	*min_node;

	set_current_position(*a);
	min_node = get_min_node(*a);
	if (min_node->current_pos <= (get_stack_size(*a) / 2))
	{
		while (*a != min_node)
			ft_ra(a);
	}
	else
	{
		while (*a != min_node)
			ft_rra(a);
	}
}

void	sort_large(t_node **a, t_node **b)
{
	push_a_to_b(a, b);
	sort_three(a);
	push_b_to_a(a, b);
	final_rotate(a);
}
