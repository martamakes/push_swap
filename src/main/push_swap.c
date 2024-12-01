/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:33 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 17:57:58 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack;

    if (argc < 2)
        return (0);
    
    stack = parse_args(argc, argv);
    if (!stack)
        return (0);
    stack->size = argc - 1;
    
    if (stack && stack->size > 0)
        print_stack(stack, "a");
    
    free_stack(stack);
    return (0);
}