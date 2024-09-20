/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:12:33 by marta             #+#    #+#             */
/*   Updated: 2024/09/19 13:33:29 by marta            ###   ########.fr       */
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
void                *ft_calloc_wrapper(size_t count, size_t size);
int                 *parse_args(int argc, char **argv, int *count);
int                 *parse_args(int argc, char **argv, int *count);
int                 count_numbers(int argc, char **argv);
int                 parse_number(const char *str, int *number);
int                 parse_quoted_numbers(const char *str, int *numbers, int *index);
int                 check_duplicates(int *numbers, int count);


#endif