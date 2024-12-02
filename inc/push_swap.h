/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:28:20 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/02 08:03:22 by mvigara-         ###   ########.fr       */
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
void        print_stack(t_stack *stack, char *stack_name);
int         add_number(t_stack *stack, char *str);

#endif