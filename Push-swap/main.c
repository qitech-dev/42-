/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:46:14 by qijin             #+#    #+#             */
/*   Updated: 2026/02/17 11:46:15 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static t_node	*ft_get_a(int argc, char **argv)
{
	t_node	*a;
	char	**args;
	int		is_malloc;

	a = NULL;
	if (argc == 2 && !argv[1][0])
		return (NULL);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		is_malloc = 1;
	}
	else
	{
		args = argv + 1;
		is_malloc = 0;
	}
	a = init_stack_a(args);
	if (is_malloc)
		free_split(args);
	return (a);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc <= 1)
		return (0);
	b = NULL;
	a = ft_get_a(argc, argv);
	if (!a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_index(a);
	if (!is_sorted(a))
		push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
