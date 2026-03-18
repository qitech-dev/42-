/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:59:27 by qijin             #+#    #+#             */
/*   Updated: 2026/02/21 20:59:28 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_to_array(t_node *stack, int size)
{
	int		i;
	t_node	*current;
	int		*arr;

	i = 0;
	current = stack;
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	while (current)
	{
		arr[i] = current->value;
		i++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (arr);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	n;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		n = i + 1;
		while (n < size)
		{
			if (arr[i] > arr[n])
			{
				tmp = arr[i];
				arr[i] = arr[n];
				arr[n] = tmp;
			}
			n++;
		}
		i++;
	}
}

static void	add_index(t_node *stack, int *arr, int size)
{
	t_node	*current;
	int		i;

	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == arr[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
		if (current == stack)
			break ;
	}
}

void	ft_index(t_node *stack)
{
	int	size;
	int	*arr;

	if (!stack)
		return ;
	size = get_stack_size(stack);
	arr = copy_to_array(stack, size);
	if (!arr)
		return ;
	sort_array(arr, size);
	add_index(stack, arr, size);
	free(arr);
}
