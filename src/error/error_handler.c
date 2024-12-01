/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:56 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 17:02:46 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_exit(void)
{
    ft_putstr_fd("Error\n", 2);
    exit(1);
}

void    free_stack(t_stack *stack)
{
    if (stack)
    {
        if (stack->numbers)
            free(stack->numbers);
        free(stack);
    }
}
