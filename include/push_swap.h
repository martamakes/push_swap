/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:12:33 by marta             #+#    #+#             */
/*   Updated: 2024/10/13 17:14:20 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
}                   t_node;

typedef struct s_stack
{
    t_node          *top;
    t_node          *bottom;
    int             size;
}                   t_stack;

void                free_stacks(t_stack **stack_a, t_stack **stack_b);
void                free_stack(t_stack **stack);
void                free_tokens(char ***tokens, int argc);
int                 *parse_args(int *argc, char **argv);
int                 *convert_to_numbers(char ***tokens, int count);
char                ***tokenize_args(int argc, char **argv);
int                 validate_and_count_numbers(char ***tokens, int *argc);
int                 check_duplicates(int *numbers, int count);
int                 is_sorted(int *numbers, int count);
t_stack	            *init_a(int *numbers, int count);
t_stack             *init_b(void);
void                sort(t_stack *a, t_stack *b);
void                sa(t_stack *a);
void                sb(t_stack *b);
void                ss(t_stack *a, t_stack *b);
void                pa(t_stack *b, t_stack *a);
void                pb(t_stack *a, t_stack *b);
void                ra(t_stack *a);
void                rb(t_stack *b);
void                rr(t_stack *a, t_stack *b);
void                rra(t_stack *a);
void                rrb(t_stack *b);
void                rrr(t_stack *a, t_stack *b);
int                 find_min_position(t_stack *stack);


#endif