/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:28:20 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/19 17:59:18 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef DEBUG
#  define VISUALS 0
# else
#  define VISUALS 1
# endif

typedef struct s_movement_impact
{
    int immediate_cost;
    int future_benefit;
    int net_cost;
} t_movement_impact;

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	bool			is_cheapest;
	struct s_stack	*next;
}		t_stack;

// Stack operations
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);

// Operations functions
void	sa(t_stack **stack_a, bool print_ops);
void	sb(t_stack **stack_b, bool print_ops);
void	ss(t_stack **stack_a, t_stack **stack_b, bool print_ops);
void	pa(t_stack **stack_a, t_stack **stack_b, bool print_ops);
void	pb(t_stack **stack_b, t_stack **stack_a, bool print_ops);
void	ra(t_stack **stack_a, bool print_ops);
void	rb(t_stack **stack_b, bool print_ops);
void	rr(t_stack **stack_a, t_stack **stack_b, bool print_ops);
void	rra(t_stack **stack_a, bool print_ops);
void	rrb(t_stack **stack_b, bool print_ops);
void	rrr(t_stack **stack_a, t_stack **stack_b, bool print_ops);

// Input processing and validation
int		is_valid_input(char *str);
int		check_duplicates(t_stack *stack);
int		process_input(int ac, char **av, t_stack **stack_a);
void	ft_split_free(char **split);

// Error handling
void	error_exit(t_stack **stack_a, t_stack **stack_b);

// Sorting algorithms
void	sort_three(t_stack **stack);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_small(t_stack **a, t_stack **b, int size);
void	turkish_sort(t_stack **a, t_stack **b);
void	move_to_b(t_stack **a, t_stack **b);
void	push_back_to_a(t_stack **a, t_stack **b);
void	return_single_node(t_stack **a, t_stack **b);

// Pre-sorting and initialization
void	init_b_stack(t_stack **a, t_stack **b);
void	push_optimal_pair(t_stack **a, t_stack **b, int first_pos, int second_pos);

// Pre-sorting utilities
void	find_min_candidates(t_stack *stack, int *first, int *second);
int		count_out_of_place(t_stack *stack);
int		is_position_optimal(int pos, int size);
void	rotate_to_position(t_stack **a, int min_pos, int size);

// Cost calculation and optimization
void	calculate_node_cost(t_stack *node, int size_curr, int size_target,
			bool is_a_to_b);
t_stack	*get_cheapest_node(t_stack *stack, bool ascending);
void	find_target_positions(t_stack *src, t_stack *dst, bool is_a_to_b);
int		calculate_weighted_cost(t_stack *node);
t_movement_impact calculate_move_impact(t_stack *a, t_stack *b, t_stack *node);

// Utils
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
int		get_min_pos(t_stack *stack);
void	do_rotations(t_stack **a, t_stack **b, t_stack *cheapest);
void	index_stack(t_stack *stack);
void	update_positions(t_stack *stack);
t_stack	*find_biggest_node(t_stack *stack);
t_stack	*find_smallest_node(t_stack *stack);
t_stack	*find_closest_target_a_to_b(t_stack *src, t_stack *dst);

// Debug and Visualization
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	print_one(t_stack *stack, char stack_name);
void	print_debug_str(char *str);
void	print_debug_nbr(int n);
void	print_debug_char(char c);
void	print_stack_index(t_stack *stack, char stack_name);
void	print_costs(t_stack *stack, char stack_name);
void	print_weighted_cost(t_stack *node, int weighted_cost);

#endif