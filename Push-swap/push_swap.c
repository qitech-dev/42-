/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:19:36 by qijin             #+#    #+#             */
/*   Updated: 2026/02/26 20:19:38 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **a)
{
	if ((*a)->index > (*a)->next->index)
		ft_sa(a);
}

void	sort_three(t_node **a)
{
	t_node	*max_node;

	max_node = get_max_node(*a);
	if (*a == max_node)
		ft_ra(a);
	else if ((*a)->next == max_node)
		ft_rra(a);
	if ((*a)->index > (*a)->next->index)
		ft_sa(a);
}

void	push_swap(t_node **a, t_node **b)
{
	int	size;

	size = get_stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else
		sort_large(a, b);
}
