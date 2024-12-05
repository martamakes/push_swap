/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:55:29 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 11:06:57 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    check_double_swap(t_stack *a, t_stack *b, t_move_info *move)
{
    int next_a;
    int next_b;

    move->can_ss = false;
    if (!a->top || !a->top->next || !b->top || !b->top->next)
        return ;
    next_a = a->top->next->value;
    next_b = b->top->next->value;
    if (next_a < a->top->value && next_b < b->top->value)
        move->can_ss = true;
}

void    calculate_cost(t_move_info *move, int size_a, int size_b)
{
    move->cost_a = move->pos_a;
    move->cost_b = move->pos_b;
    move->rev_a = false;
    move->rev_b = false;
    if (move->pos_a > size_a / 2)
    {
        move->rev_a = true;
        move->cost_a = size_a - move->pos_a;
    }
    if (move->pos_b > size_b / 2)
    {
        move->rev_b = true;
        move->cost_b = size_b - move->pos_b;
    }
    move->total_cost = move->cost_a + move->cost_b;
    if (move->rev_a == move->rev_b)
        move->total_cost -= ft_min(move->cost_a, move->cost_b);
}

void    find_best_move(t_stack *a, t_stack *b, t_move_info *best)
{
    t_node      *current;
    t_move_info tmp;
    int         i;

    current = b->top;