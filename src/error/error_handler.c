/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:56 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 18:24:16 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_exit(void)
{
    ft_putstr_fd("Error\n", 2);
    exit(1);
}

void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *temp;

    if (!stack)
        return ;
    current = stack->top;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    free(stack);
}
