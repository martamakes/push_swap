/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:53:31 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 17:53:35 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_last(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

static int check_duplicate(t_stack *stack, int num)
{
    while (stack)
    {
        if (stack->value == num)
            return (1);
        stack = stack->next;
    }
    return (0);
}

int add_number(t_stack **stack, char *str)
{
    t_stack     *new;
    t_stack     *last;
    long long   num;

    if (!is_valid_number(str))
        return (0);
    num = ft_atoll(str);
    if (num > INT_MAX || num < INT_MIN)
        return (0);
    if (check_duplicate(*stack, (int)num))
        return (0);
    new = init_stack((int)num);
    if (!new)
        return (0);
    if (!*stack)
        *stack = new;
    else
    {
        last = find_last(*stack);
        last->next = new;
    }
    return (1);
}
