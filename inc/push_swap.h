/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:28:20 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/15 04:58:48 by mvigara-         ###   ########.fr       */
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

typedef struct s_chunk
{
    int     min;        // Valor mínimo del stack
    int     max;        // Valor máximo del stack
    int     chunk_size; // Tamaño de cada chunk
    int     num_chunks; // Número total de chunks
    int     current;    // Chunk actual siendo procesado
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
void            free_split(char **split);
int             add_number(t_stack *stack, char *str);

// Operaciones básicas del stack
void swap_top(t_stack *stack);
void            sa(t_stack *stack_a);
void            sb(t_stack *stack_b);
void            ss(t_stack *stack_a, t_stack *stack_b);
void            pa(t_stack *stack_a, t_stack *stack_b);
void            pb(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void            ra(t_stack *stack_a);
void            rb(t_stack *stack_b);
void            rr(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
void            rra(t_stack *stack_a);
void            rrb(t_stack *stack_b);
void            rrr(t_stack *stack_a, t_stack *stack_b);

// Algoritmos de ordenación
void            sort_two(t_stack *stack_a);
void            sort_three(t_stack *stack_a, char c);
void            sort_five(t_stack *stack_a, t_stack *stack_b);
void            sort_large(t_stack *stack_a, t_stack *stack_b);
void            sort_medium(t_stack *a, t_stack *b);

// Funciones de utilidad para sort_large
void            init_chunk_info(t_stack *a, t_chunk *chunk);
void            push_chunks_to_b(t_stack *a, t_stack *b, t_chunk *chunk);
void            push_back_to_a(t_stack *a, t_stack *b);
int             get_chunk_start(t_chunk *chunk);
int             get_chunk_end(t_chunk *chunk);
bool            is_in_current_chunk(int value, t_chunk *chunk);
void            calculate_move_cost(t_stack *a, t_stack *b, t_move *move);
void            execute_move(t_stack *a, t_stack *b, t_move *move);

// Funciones auxiliares
int             is_sorted(t_stack *stack);
void            get_stack_bounds(t_stack *stack, int *min, int *max);
int             get_position(t_stack *stack, int value);
int             get_target_position(t_stack *a, int value);
int             get_min_pos(t_stack *stack);
int             get_max_pos(t_stack *stack);
int get_highest_pos(t_stack *stack); //ver si pudeo sustituir con get_max_pos
void            rotate_both(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
void            rev_rotate_both(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
void    rotate_to_min(t_stack *a);

// Funciones de debug (a mantener temporalmente)
void            simple_print_stack(t_stack *stack, char *stack_name);
void            print_stack(t_stack *stack, char *stack_name);
void            print_chunk_info(t_chunk *chunk);
void            print_move_info(t_move *move);

#endif