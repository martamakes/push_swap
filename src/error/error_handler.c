/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:56 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 11:43:38 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error_exit(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_a != NULL)
        free_stack(stack_a);
    if (stack_b != NULL)
        free_stack(stack_b);
    ft_putstr_fd("Error\n", 2);
    exit(1);
}
