/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:22:43 by qijin             #+#    #+#             */
/*   Updated: 2026/02/19 18:22:47 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_core(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;
	t_node	*third;

	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = first->next;
	if (second->next == first)
	{
		*stack = second;
		return ;
	}
	last = first->prev;
	third = second->next;
	last->next = second;
	second->prev = last;
	second->next = first;
	first->prev = second;
	first->next = third;
	third->prev = first;
	*stack = second;
}

void	ft_sa(t_node **a)
{
	swap_core(a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_node **b)
{
	swap_core(b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_node **a, t_node **b)
{
	int	moved;

	moved = 0;
	if (a || *a || (*a)->next == *a)
	{
		swap_core(a);
		moved = 1;
	}
	if (a || *a || (*a)->next == *a)
	{
		swap_core(b);
		moved = 1;
	}
	if (moved)
		write(1, "ss\n", 3);
}
