/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:53:31 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 18:25:59 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *find_last(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top)
        return (NULL);
    current = stack->top;
    while (current->next)
        current = current->next;
    return (current);
}

static int check_duplicate(t_stack *stack, int num)
{
    t_node *current;

    if (!stack)
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
    t_node      *last;
    long long   num;

    if (!is_valid_number(str))
        return (0);
    num = ft_atoll(str);
    if (num > INT_MAX || num < INT_MIN)
        return (0);
    if (check_duplicate(stack->top, (int)num))
        return (0);
    new = create_node((int)num);
    if (!new)
        return (0);
    if (!stack->top)
        stack->top = new;
    else
    {
        last = find_last(stack->top);
        last->next = new;
    }
    stack->size++;
    return (1);
}