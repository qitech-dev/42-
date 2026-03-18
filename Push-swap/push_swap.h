/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:31:34 by qijin             #+#    #+#             */
/*   Updated: 2026/02/17 20:31:36 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				current_pos;
	int				push_cost;
	int				cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
long int	ft_atoi(const char *str);
void		free_stack(t_node **stack);
t_node		*ft_dl_new(int value);
void		ft_dl_add_back(t_node **stack, t_node *new_node);
t_node		*init_stack_a(char **args);
void		ft_index(t_node *stack);
int			get_stack_size(t_node *stack);
t_node		*get_max_node(t_node *stack);
t_node		*get_min_node(t_node *stack);
void		set_current_position(t_node *stack);
int			is_sorted(t_node *stack);
void		set_target_a(t_node *a, t_node *b);
void		set_target_b(t_node *b, t_node *a);
void		calculate_cost_a(t_node *a, t_node *b);
void		set_cheapest(t_node *stack);
t_node		*get_cheapest_node(t_node *stack);
void		move_a_to_b(t_node **a, t_node **b);
void		sort_three(t_node **a);
void		ft_sa(t_node **a);
void		ft_sb(t_node **b);
void		ft_ss(t_node **a, t_node **b);
void		ft_pa(t_node **a, t_node **b);
void		ft_pb(t_node **b, t_node **a);
void		ft_ra(t_node **a);
void		ft_rb(t_node **b);
void		ft_rr(t_node **a, t_node **b);
void		ft_rra(t_node **a);
void		ft_rrb(t_node **b);
void		ft_rrr(t_node **a, t_node **b);
void		sort_large(t_node **a, t_node **b);
void		push_swap(t_node **a, t_node **b);

#endif
