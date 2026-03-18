/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:46:31 by qijin             #+#    #+#             */
/*   Updated: 2026/03/01 18:46:32 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	found_target_for_a(t_node *curr_a, t_node *b)
{
	t_node	*curr_b;
	t_node	*target;
	long	best_match;

	best_match = LONG_MIN;
	curr_b = b;
	target = NULL;
	while (curr_b)
	{
		if (curr_b->index < curr_a->index && curr_b->index > best_match)
		{
			best_match = curr_b->index;
			target = curr_b;
		}
		curr_b = curr_b->next;
		if (curr_b == b)
			break ;
	}
	if (target == NULL)
		curr_a->target_node = get_max_node(b);
	else
		curr_a->target_node = target;
}

void	set_target_a(t_node *a, t_node *b)
{
	t_node	*curr_a;

	curr_a = a;
	while (curr_a)
	{
		found_target_for_a(curr_a, b);
		curr_a = curr_a->next;
		if (curr_a == a)
			break ;
	}
}

static void	found_target_for_b(t_node *a, t_node *curr_b)
{
	t_node	*curr_a;
	long	best_match;
	t_node	*target;

	best_match = LONG_MAX;
	curr_a = a;
	target = NULL;
	while (curr_a)
	{
		if (curr_a->index > curr_b->index && curr_a->index < best_match)
		{
			best_match = curr_a->index;
			target = curr_a;
		}
		curr_a = curr_a->next;
		if (curr_a == a)
			break ;
	}
	if (target == NULL)
		curr_b->target_node = get_min_node(a);
	else
		curr_b->target_node = target;
}

void	set_target_b(t_node *a, t_node *b)
{
	t_node	*curr_b;

	curr_b = b;
	while (curr_b)
	{
		found_target_for_b(a, curr_b);
		curr_b = curr_b->next;
		if (curr_b == b)
			break ;
	}
}
