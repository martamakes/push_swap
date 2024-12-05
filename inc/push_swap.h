/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:28:20 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 13:26:01 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
}                   t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
    t_node  *bottom;
}           t_stack;

typedef struct s_chunk_info
{
    int     start;
    int     end;
    int     total;
    int     current;
}           t_chunk_info;

// En push_swap.h, modificar t_cost para incluir todos los campos necesarios:
typedef struct s_cost
{
    int     cost_a;
    int     cost_b;
    int     pos_a;
    int     pos_b;
    int     total_cost;
    bool    rev_a;
    bool    rev_b;
    bool    can_ss;
    bool    needs_swap;
    int     value;
}           t_cost;

void            error_exit(void);
void            free_stack(t_stack *stack);
t_stack         *init_stack(void);
t_node          *create_node(int value);
t_stack         *parse_args(int argc, char **argv);
int             is_valid_number(char *str);
void            free_split(char **split);
int             add_number(t_stack *stack, char *str);

void            sa(t_stack *stack_a);
void            sb(t_stack *stack_b);
void            ss(t_stack *stack_a, t_stack *stack_b);
void            pa(t_stack *stack_a, t_stack *stack_b);
void            pb(t_stack *stack_a, t_stack *stack_b);
void            ra(t_stack *stack_a);
void            rb(t_stack *stack_b);
void            rr(t_stack *stack_a, t_stack *stack_b);
void            rra(t_stack *stack_a);
void            rrb(t_stack *stack_b);
void            rrr(t_stack *stack_a, t_stack *stack_b);

void            sort_two(t_stack *stack_a);
void            sort_three(t_stack *stack_a);
void            sort_five(t_stack *stack_a, t_stack *stack_b);
void            sort_large(t_stack *stack_a, t_stack *stack_b);
int             is_sorted(t_stack *stack);

void            get_chunk_limits(t_stack *stack, int chunk_index, 
                    int *chunk_start, int *chunk_end);
t_chunk_info    *init_chunk_info(t_stack *stack);
void            free_chunk_info(t_chunk_info *chunk_info);
int             is_in_chunk(int value, int chunk_start, int chunk_end);
int             count_numbers_in_chunk(t_stack *stack, int start, int end);
int             get_value_at_position(t_stack *stack, int pos);

void            push_optimal_number(t_stack *a, t_stack *b, 
                    int chunk_start, int chunk_end);
int             calculate_position_cost(int pos, int stack_size, bool *reverse);
int             calculate_total_cost(t_cost *cost);
void            move_to_b(t_stack *a, t_stack *b, t_chunk_info *chunk);
void            move_back_to_a(t_stack *a, t_stack *b);
void    complete_rotations(t_stack *stack, int count, int reverse);
void    get_stack_bounds(t_stack *stack, int *min, int *max);
int     get_min_pos(t_stack *stack);
int     get_max_pos(t_stack *stack);
int     get_highest_pos(t_stack *stack);
void    init_cost(t_cost *cost);
void    execute_optimal_moves(t_stack *a, t_stack *b, t_cost *cost);
void    calculate_target_position(t_stack *a, int value, t_cost *cost);
bool    would_improve_a(t_stack *a);
bool    would_improve_b(t_stack *b, t_stack *a);
bool    is_optimal_double_swap(t_stack *a, t_stack *b);

#endif