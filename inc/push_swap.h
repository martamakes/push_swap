/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:28:20 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/02 09:08:54 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct  s_node  *prev;
}                   t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
    t_node  *bottom;
}           t_stack;

// Error handling
void        error_exit(void);
void        free_stack(t_stack *stack);

// Stack operations
t_stack     *init_stack(void);
t_node      *create_node(int value);

// Parsing functions
t_stack     *parse_args(int argc, char **argv);
int         is_valid_number(char *str);
void        free_split(char **split);
int         add_number(t_stack *stack, char *str);

// Basic stack operations
void        sa(t_stack *stack_a);
void        sb(t_stack *stack_b);
void        ss(t_stack *stack_a, t_stack *stack_b);
void        pa(t_stack *stack_a, t_stack *stack_b);
void        pb(t_stack *stack_a, t_stack *stack_b);
void        ra(t_stack *stack_a);
void        rb(t_stack *stack_b);
void        rr(t_stack *stack_a, t_stack *stack_b);
void        rra(t_stack *stack_a);
void        rrb(t_stack *stack_b);
void        rrr(t_stack *stack_a, t_stack *stack_b);

// Sorting algorithms
void        sort_two(t_stack *stack_a);
void        sort_three(t_stack *stack_a);
void        sort_five(t_stack *stack_a, t_stack *stack_b);
void        sort_medium(t_stack *stack_a, t_stack *stack_b);
void        sort_large(t_stack *stack_a, t_stack *stack_b);
int         is_sorted(t_stack *stack);
int         get_highest_pos(t_stack *stack);


//Debug
void        test_swaps(t_stack *stack_a, t_stack *stack_b);
void        print_stack(t_stack *stack, char *stack_name);
void        simple_print_stack(t_stack *stack, char *stack_name);
void        test_rotations(t_stack *stack_a, t_stack *stack_b);
void        test_reverse_rotations(t_stack *stack_a, t_stack *stack_b);
void        test_all_operations(t_stack *stack_a, t_stack *stack_b);


#endif