/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 04:51:12 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/16 13:43:26 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    execute_rotation(t_stack *stack, int cost, char stack_name)
{
    while (cost)
    {
        if (cost > 0)
        {
            if (stack_name == 'a')
                ra(stack);
            else
                rb(stack);
            cost--;
        }
        else
        {
            if (stack_name == 'a')
                rra(stack);
            else
                rrb(stack);
            cost++;
        }
    }
}

static void    execute_double_moves(t_stack *a, t_stack *b, t_move *move)
{
    while (move->cost_a && move->cost_b && 
           ((move->cost_a > 0 && move->cost_b > 0) || 
            (move->cost_a < 0 && move->cost_b < 0)))
    {
        if (move->cost_a > 0)
        {
            rr(a, b);
            move->cost_a--;
            move->cost_b--;
        }
        else
        {
            rrr(a, b);
            move->cost_a++;
            move->cost_b++;
        }
    }
    execute_rotation(a, move->cost_a, 'a');
    execute_rotation(b, move->cost_b, 'b');
    pa(a, b);
}

static void    find_best_move(t_stack *a, t_stack *b, t_move *best)
{
    t_node  *current;
    t_move  tmp;
    int     found_better;

    if (!a || !b || !best || !b->top)
        return;
    
    current = b->top;
    found_better = 0;
    while (current && current->next)  // Cambiado para evitar buffer overflow
    {
        init_move(&tmp);
        tmp.value = current->value;
        calculate_move_cost(a, b, &tmp);

        if (!found_better || tmp.total_cost < best->total_cost)
        {
            *best = tmp;
            found_better = 1;
        }
        current = current->next;
    }
}

void    push_back(t_stack *a, t_stack *b)
{
    t_move  best;

    while (b->size > 0)
    {
        init_move(&best);
        best.total_cost = INT_MAX;
        find_best_move(a, b, &best);
        execute_double_moves(a, b, &best);
    }
}
