/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:39:49 by qijin             #+#    #+#             */
/*   Updated: 2026/02/25 20:39:50 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	get_min_cost(int ra, int rra, int rb, int rrb)
{
	int	cost_rr;
	int	cost_rrr;
	int	cost_ra_rrb;
	int	cost_rra_rb;
	int	min;

	cost_rr = ft_max(ra, rb);
	cost_rrr = ft_max(rra, rrb);
	cost_ra_rrb = ra + rrb;
	cost_rra_rb = rra + rb;
	min = cost_rr;
	if (cost_rrr < min)
		min = cost_rrr;
	if (cost_ra_rrb < min)
		min = cost_ra_rrb;
	if (cost_rra_rb < min)
		min = cost_rra_rb;
	return (min);
}

static void	update_node_cost(t_node *node, int size_a, int size_b)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	ra = node->current_pos;
	rb = node->target_node->current_pos;
	rra = 0;
	if (ra > 0)
		rra = size_a - ra;
	rrb = 0;
	if (rb > 0)
		rrb = size_b - rb;
	node->push_cost = get_min_cost(ra, rra, rb, rrb);
}

void	calculate_cost_a(t_node *a, t_node *b)
{
	int		size_a;
	int		size_b;
	t_node	*curr_a;

	if (!a || !b)
		return ;
	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	curr_a = a;
	while (curr_a)
	{
		update_node_cost(curr_a, size_a, size_b);
		curr_a = curr_a->next;
		if (curr_a == a)
			break ;
	}
}
