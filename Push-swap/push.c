/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 19:26:21 by qijin             #+#    #+#             */
/*   Updated: 2026/02/21 19:26:23 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_be_moved(t_node **stack, t_node *first)
{
	if (first->next == first)
		*stack = NULL;
	else
	{
		first->prev->next = first->next;
		first->next->prev = first->prev;
		*stack = first->next;
	}
}

void	ft_pa(t_node **a, t_node **b)
{
	t_node	*b_first;
	t_node	*last;

	if (!b || !*b)
		return ;
	b_first = *b;
	ft_be_moved(b, b_first);
	if (*a == NULL)
	{
		*a = b_first;
		b_first->prev = b_first;
		b_first->next = b_first;
	}
	else
	{
		last = (*a)->prev;
		b_first->prev = last;
		b_first->next = *a;
		last->next = b_first;
		(*a)->prev = b_first;
		*a = b_first;
	}
	write(1, "pa\n", 3);
}

void	ft_pb(t_node **b, t_node **a)
{
	t_node	*a_first;
	t_node	*last;

	if (!a || !*a)
		return ;
	a_first = *a;
	ft_be_moved(a, a_first);
	if (*b == NULL)
	{
		*b = a_first;
		a_first->prev = a_first;
		a_first->next = a_first;
	}
	else
	{
		last = (*b)->prev;
		a_first->prev = last;
		a_first->next = *b;
		last->next = a_first;
		(*b)->prev = a_first;
		*b = a_first;
	}
	write(1, "pb\n", 3);
}
