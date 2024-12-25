/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:28:20 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/24 17:09:20 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/inc/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef DEBUG
#  define VISUALS 0
# else
#  define VISUALS 1
# endif

typedef struct s_stack
{
	int value;            // Valor numérico del nodo
	int index;            // Índice para ordenación
	int pos;              // Posición actual en el stack
	int target_pos;       // Posición objetivo en el otro stack
	int cost_a;           // Coste de mover en stack a
	int cost_b;           // Coste de mover en stack b
	struct s_stack *next; // Puntero al siguiente nodo
}		t_stack;

// Stack operations
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);
// Operations functions
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

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

// Utils
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
int		get_min_pos(t_stack *stack);
void	do_rotations(t_stack **a, t_stack **b, t_stack *cheapest);
void    index_stack(t_stack *stack);
void	turkish_sort(t_stack **a, t_stack **b);
void	get_cost(t_stack *a, t_stack *b);
void	get_target_positions(t_stack *a, t_stack *b);
void	get_target_positions_b(t_stack *b, t_stack *a);
void	sort_small(t_stack **a, t_stack **b, int size);
t_stack	*get_cheapest(t_stack *stack);
void	move_cheapest_to_a(t_stack **a, t_stack **b);
void	move_cheapest_to_b(t_stack **a, t_stack **b);
void	shift_stack(t_stack **stack);
void	update_positions(t_stack *stack);
int		find_target_pos_b_to_a(t_stack *b_node, t_stack *stack_a);
int		find_target_pos_a_to_b(t_stack *a_node, t_stack *stack_b);

// debug
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	print_one(t_stack *stack, char stack_name);
void	print_debug_str(char *str);
void	print_debug_nbr(int n);
void	print_debug_char(char c);
void    print_stack_index(t_stack *stack, char stack_name);

#endif