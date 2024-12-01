/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:28:20 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 17:58:15 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
    int             value;
    int             size;
    struct s_stack  *next;
}                   t_stack;

// Error handling
void        error_exit(void);
void        free_stack(t_stack *stack);

// Stack operations
t_stack     *init_stack(int size);

// Parsing functions
t_stack     *parse_args(int argc, char **argv);
int         is_valid_number(char *str);
void        free_split(char **split);
void        print_stack(t_stack *stack, char *stack_name);
int         add_number(t_stack **stack, char *str);



#endif