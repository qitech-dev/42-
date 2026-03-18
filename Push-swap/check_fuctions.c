/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fuctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:49:00 by qijin             #+#    #+#             */
/*   Updated: 2026/02/19 14:49:03 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i] || str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*If it's a doubly linked circular list,
break the loop to make it a regular linked list ending with NULL.
To be compatible with both "closed loops" and "unclosed long chains".*/

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*curr;

	curr = *stack;
	if (!stack || !*stack)
		return ;
	if (curr->prev)
		curr->prev->next = NULL;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}

static int	check_duplicate_in_stack(t_node *a, int n)
{
	t_node	*curr;

	if (!a)
		return (0);
	curr = a;
	while (curr)
	{
		if (curr->value == n)
			return (1);
		curr = curr->next;
		if (curr == a)
			break ;
	}
	return (0);
}

t_node	*init_stack_a(char **args)
{
	t_node		*a;
	t_node		*new_node;
	long int	tmp;
	int			i;

	a = NULL;
	i = 0;
	while (args[i])
	{
		if (!ft_check_num(args[i]))
			return (free_stack(&a), NULL);
		tmp = ft_atoi(args[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (free_stack(&a), NULL);
		if (check_duplicate_in_stack(a, (int)tmp))
			return (free_stack(&a), NULL);
		new_node = ft_dl_new((int)tmp);
		if (!new_node)
			return (free_stack(&a), NULL);
		ft_dl_add_back(&a, new_node);
		i++;
	}
	return (a);
}
