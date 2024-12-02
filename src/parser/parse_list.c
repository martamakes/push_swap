/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:53:31 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/02 07:56:25 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *find_last(t_stack *stack)
{
    t_node  *current;

    if (!stack || !stack->top)
        return (NULL);
    current = stack->top;
    while (current->next)
        current = current->next;
    return (current);
}

static int check_duplicate(t_stack *stack, int num)
{
    t_node  *current;

    if (!stack || !stack->top)
        return (0);
    current = stack->top;
    while (current)
    {
        if (current->value == num)
            return (1);
        current = current->next;
    }
    return (0);
}

int add_number(t_stack *stack, char *str)
{
    t_node      *new;
    long long   num;

    if (!stack || !is_valid_number(str))
        return (0);
    num = ft_atoll(str);
    if (num > INT_MAX || num < INT_MIN)
        return (0);
    if (check_duplicate(stack, (int)num))
        return (0);
    new = create_node((int)num);
    if (!new)
        return (0);
    
    ft_printf("Debug: Adding number %d to stack\n", (int)num);
    
    if (!stack->top)
    {
        stack->top = new;
        stack->bottom = new;
        ft_printf("Debug: First node added - value: %d\n", new->value);
    }
    else
    {
        new->prev = stack->bottom;
        stack->bottom->next = new;
        stack->bottom = new;
        ft_printf("Debug: Node added - value: %d, prev value: %d\n", 
                 new->value, new->prev->value);
    }
    
    stack->size++;
    return (1);
}
