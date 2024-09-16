/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:12:33 by marta             #+#    #+#             */
/*   Updated: 2024/09/16 11:53:33 by marta            ###   ########.fr       */
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
    t_node          *top;
    t_node          *bottom;
    int             size;
}                   t_stack;

void free_stacks(t_stack **stack_a, t_stack **stack_b);
void free_stack(t_stack **stack);


#endif