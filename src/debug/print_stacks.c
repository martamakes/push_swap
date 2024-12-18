/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:25:00 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/18 07:39:28 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stacks(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *temp_a = stack_a;
    t_stack *temp_b = stack_b;
    
    if (!DEBUG)
        return ;

    ft_putstr_fd("\nStack A: ", 1);
    while (temp_a)
    {
        ft_putnbr_fd(temp_a->value, 1);
        temp_a = temp_a->next;
        if (temp_a)
            ft_putstr_fd(" ", 1);
    }
    ft_putchar_fd('\n', 1);

    ft_putstr_fd("Stack B: ", 1);
    while (temp_b)
    {
        ft_putnbr_fd(temp_b->value, 1);
        temp_b = temp_b->next;
        if (temp_b)
            ft_putstr_fd(" ", 1);
    }
    ft_putstr_fd("\n\n", 1);
}

void    print_one(t_stack *stack, char stack_name)
{
    t_stack *temp = stack;
    
    if (!DEBUG)
        return ;

    ft_putstr_fd("\nStack ", 1);
    ft_putchar_fd(stack_name, 1);
    ft_putstr_fd(": ", 1);
    while (temp)
    {
        ft_putnbr_fd(temp->value, 1);
        temp = temp->next;
        if (temp)
            ft_putstr_fd(" ", 1);
    }
    ft_putstr_fd("\n\n", 1);
}
