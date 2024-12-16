/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:33 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/16 13:37:01 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    sort_stack(t_stack *stack_a)
{
    t_stack    *stack_b;

    if (!stack_a || stack_a->size < 2 || is_sorted(stack_a))
        return ;   
    if (stack_a->size == 2)
    {
        sort_two(stack_a);
        return ;
    }
    if (stack_a->size == 3)
    {
        sort_three(stack_a, 'a');
        return ;
    }
    stack_b = init_stack();
    if (!stack_b)
        return ;    
    if (stack_a->size <= 5)
        sort_medium(stack_a, stack_b);
    else
        sort_large(stack_a, stack_b);    
    free_stack(stack_b);
}

int    main(int argc, char **argv)
{
    t_stack    *stack_a;

    if (argc < 2)
        return (0);
    stack_a = parse_args(argc, argv);
    if (!stack_a)
        error_exit();
    sort_stack(stack_a);
    free_stack(stack_a);
    return (0);
}
