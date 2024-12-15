/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 04:51:12 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/15 04:51:40 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    execute_rotation(t_stack *stack, int cost, char stack_name)
{
    while (cost > 0)
    {
        if (stack_name == 'a')
            ra(stack);
        else
            rb(stack);
        cost--;
    }
}

static void    execute_rev_rotation(t_stack *stack, int cost, char stack_name)
{
    while (cost > 0)
    {
        if (stack_name == 'a')
            rra(stack);
        else
            rrb(stack);
        cost--;
    }
}

static void    execute_move(t_stack *a, t_stack *b, t_move *move)
{
    // Ejecutar rotaciones dobles primero si es posible
    while (move->rev_a == move->rev_b && move->cost_a > 0 && move->cost_b > 0)
    {
        if (move->rev_a)
            rrr(a, b);
        else
            rr(a, b);
        move->cost_a--;
        move->cost_b--;
    }

    // Completar rotaciones individuales restantes
    if (move->rev_a)
        execute_rev_rotation(a, move->cost_a, 'a');
    else
        execute_rotation(a, move->cost_a, 'a');

    if (move->rev_b)
        execute_rev_rotation(b, move->cost_b, 'b');
    else
        execute_rotation(b, move->cost_b, 'b');

    // Realizar el push
    pa(a, b);
}

void    push_back_to_a(t_stack *a, t_stack *b)
{
    t_move  current;
    t_move  best;
    t_node  *tmp;
    int     found_better;

    while (b->size > 0)
    {
        found_better = 0;
        tmp = b->top;
        init_move(&best);
        best.total_cost = INT_MAX;

        while (tmp)
        {
            init_move(&current);
            current.value = tmp->value;
            calculate_move_cost(a, b, &current);

            if (current.total_cost < best.total_cost)
            {
                best = current;
                found_better = 1;
            }
            tmp = tmp->next;
        }

        if (found_better)
            execute_move(a, b, &best);
    }
}
