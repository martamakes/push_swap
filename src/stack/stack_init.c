/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:46:40 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 15:46:43 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(int size)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        error_exit();
    stack->size = size;
    stack->numbers = malloc(sizeof(int) * size);
    if (!stack->numbers)
    {
        free(stack);
        error_exit();
    }
    return (stack);
}
