/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:30:37 by qijin             #+#    #+#             */
/*   Updated: 2026/02/23 14:30:39 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_node *stack)
{
	t_node	*curr;
	t_node	*target;
	long	best_match;

	if (!stack)
		return ;
	curr = stack;
	best_match = LONG_MAX;
	target = stack;
	while (curr)
	{
		curr->cheapest = 0;
		if (curr->push_cost < best_match)
		{
			target = curr;
			best_match = curr->push_cost;
		}
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	target->cheapest = 1;
}

t_node	*get_cheapest_node(t_node *stack)
{
	t_node	*curr;

	if (!stack)
		return (NULL);
	curr = stack;
	while (curr)
	{
		if (curr->cheapest == 1)
			return (curr);
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (NULL);
}
