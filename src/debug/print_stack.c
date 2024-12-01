/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:52:29 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 15:52:32 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack(t_stack *stack, char *stack_name)
{
    int i;

    ft_printf("\n=== Stack %s ===\n", stack_name);
    if (!stack || !stack->numbers)
    {
        ft_printf("(empty)\n");
        return ;
    }
    ft_printf("Size: %d\n", stack->size);
    i = 0;
    while (i < stack->size)
    {
        ft_printf("[%d]: %d\n", i, stack->numbers[i]);
        i++;
    }
    ft_printf("=============\n\n");
}