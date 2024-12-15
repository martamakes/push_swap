/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:19:17 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/15 04:33:58 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void optimize_push(t_stack *stack, char c)
{
    if(stack->size > 1)
    {
        if(stack->top->value < stack->top->next->value)
        {
            swap_top(stack);
            ft_printf("s%c\n", c);
        }     
    }
    if (stack->size == 3)
        sort_three(stack, c);
    else
        return;
}

void    sort_medium(t_stack *a, t_stack *b)
{
    int optimal_position;
    t_move *moves;
    
    if (!a || !b)
        return ;
    moves = malloc(sizeof(t_move));
    if (!moves)
        return;
    ft_memset(moves, 0, sizeof(t_move));
    while (a->size > 3)
    {
        pb(a, b);
        a->size--;
        b->size++;
        optimize_push(b, 'b');
        calculate_move_cost(b, a, moves);
        push_to_b(a, b);
    }
    sort_three(a, 'a');
    calculate_move_cost(a, b, moves);
    push_back_to_a(a, b);
    free(moves);
}
