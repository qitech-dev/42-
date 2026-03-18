/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:01:36 by qijin             #+#    #+#             */
/*   Updated: 2026/02/23 19:01:37 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_max_node(t_node *stack)
{
	t_node	*max_node;
	t_node	*curr;
	int		max_index;

	if (!stack)
		return (NULL);
	max_index = 0;
	max_node = stack;
	curr = stack;
	while (curr)
	{
		if (curr->index > max_index)
		{
			max_node = curr;
			max_index = curr->index;
		}
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (max_node);
}

t_node	*get_min_node(t_node *stack)
{
	t_node	*min_node;
	t_node	*curr;
	int		min_index;

	if (!stack)
		return (NULL);
	min_index = get_stack_size(stack) + 1;
	min_node = stack;
	curr = stack;
	while (curr)
	{
		if (curr->index < min_index)
		{
			min_node = curr;
			min_index = curr->index;
		}
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (min_node);
}

void	set_current_position(t_node *stack)
{
	int		pos;
	t_node	*curr;

	if (!stack)
		return ;
	pos = 0;
	curr = stack;
	while (curr)
	{
		curr->current_pos = pos;
		pos++;
		curr = curr->next;
		if (curr == stack)
			break ;
	}
}

int	is_sorted(t_node *stack)
{
	t_node	*curr;

	if (!stack)
		return (1);
	curr = stack;
	while (curr->next != stack)
	{
		if (curr->next->index != (curr->index + 1))
			return (0);
		curr = curr->next;
	}
	return (1);
}
