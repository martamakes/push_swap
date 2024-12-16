/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:28:20 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/16 13:06:14 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
    int             value;
    int             index;     // Añadido para la estrategia de indexación
    int             pos;       // Posición actual en el stack
    int             target;    // Posición objetivo
    int             cost_a;    // Coste de mover en stack a
    int             cost_b;    // Coste de mover en stack b
    struct s_node   *next;
    struct s_node   *prev;
}                   t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
    t_node  *bottom;
}           t_stack;

typedef struct s_chunk
{
    int     min;
    int     max;
    int     chunk_size;
    int     num_chunks;
    int     current;
}           t_chunk;

typedef struct s_move
{
    int     value;      // Valor a mover
    int     cost_a;     // Coste de rotaciones en A
    int     cost_b;     // Coste de rotaciones en B
    int     pos_a;      // Posición objetivo en A
    int     pos_b;      // Posición actual en B
    bool    rev_a;      // Usar reverse rotate en A
    bool    rev_b;      // Usar reverse rotate en B
    int     total_cost; // Coste total del movimiento
}           t_move;

// Funciones de inicialización y liberación
void            error_exit(void);
void            free_stack(t_stack *stack);
t_stack         *init_stack(void);
t_node          *create_node(int value);

// Funciones de parseo
t_stack         *parse_args(int argc, char **argv);
int             is_valid_number(char *str);

// Operaciones básicas del stack
void            swap_top(t_stack *stack);
void            sa(t_stack *stack_a);
void            sb(t_stack *stack_b);
void            ss(t_stack *stack_a, t_stack *stack_b);
void            pa(t_stack *stack_a, t_stack *stack_b);
void            pb(t_stack *stack_a, t_stack *stack_b);
void            rotate(t_stack *stack);
void            ra(t_stack *stack_a);
void            rb(t_stack *stack_b);
void            rr(t_stack *stack_a, t_stack *stack_b);
void            reverse_rotate(t_stack *stack);
void            rra(t_stack *stack_a);
void            rrb(t_stack *stack_b);
void            rrr(t_stack *stack_a, t_stack *stack_b);

// Algoritmos de ordenación
void            sort_two(t_stack *stack_a);
void            sort_three(t_stack *stack_a, char c);
void            sort_medium(t_stack *a, t_stack *b);
void            sort_large(t_stack *a, t_stack *b);

// Funciones de posición y costes
int             get_position(t_stack *stack, int value);
int             get_target_position_value(t_stack *a, int value);
void            get_stack_position(t_stack *stack);
void            calculate_cost(t_stack *a, t_stack *b);
void            execute_cheapest_move(t_stack *a, t_stack *b);
void            do_move(t_stack *a, t_stack *b, int cost_a, int cost_b);

// Funciones de indexación
void            get_index(t_stack *stack_a, int stack_size);
int             get_lowest_index_position(t_stack *stack);

// Funciones auxiliares
int             is_sorted(t_stack *stack);
void            get_stack_bounds(t_stack *stack, int *min, int *max);
int             get_min_pos(t_stack *stack);
int             get_max_pos(t_stack *stack);
void            rotate_to_min(t_stack *a);

// Funciones de chunks (solo para números >100)
void            init_chunk_info(t_stack *a, t_chunk *chunk);
void            push_chunks_to_b(t_stack *a, t_stack *b, t_chunk *chunk);
int             get_chunk_start(t_chunk *chunk);
int             get_chunk_end(t_chunk *chunk);
bool            is_in_current_chunk(int value, t_chunk *chunk);

// Funciones de debug
void            simple_print_stack(t_stack *stack, char *stack_name);

#endif