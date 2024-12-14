/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:19:12 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/14 19:19:15 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_move(t_move *move)
{
    if (!move)
        return ;
    move->value = 0;
    move->cost_a = 0;
    move->cost_b = 0;
    move->pos_a = 0;
    move->pos_b = 0;
    move->rev_a = false;
    move->rev_b = false;
    move->total_cost = 0;
}

static int    get_rotation_cost(int pos, int size)
{
    if (pos <= size / 2)
        return (pos);
    return (size - pos);
}

static void    calculate_costs(t_move *move, t_stack *a, t_stack *b)
{
    int size_a;
    int size_b;

    if (!move || !a || !b)
        return ;
    
    size_a = a->size;
    size_b = b->size;

    // Calcular si es mejor rotar hacia arriba o abajo
    if (move->pos_a <= size_a / 2)
        move->rev_a = false;
    else
    {
        move->rev_a = true;
        move->pos_a = size_a - move->pos_a;
    }

    if (move->pos_b <= size_b / 2)
        move->rev_b = false;
    else
    {
        move->rev_b = true;
        move->pos_b = size_b - move->pos_b;
    }

    // Calcular costes individuales
    move->cost_a = move->pos_a;
    move->cost_b = move->pos_b;

    // Calcular coste total optimizado
    if (move->rev_a == move->rev_b)
        move->total_cost = move->cost_a > move->cost_b ? 
            move->cost_a : move->cost_b;
    else
        move->total_cost = move->cost_a + move->cost_b;
}

void    calculate_move_cost(t_stack *a, t_stack *b, t_move *move)
{
    if (!a || !b || !move)
        return ;

    // Calcular posición objetivo en A
    move->pos_a = get_target_position(a, move->value);
    
    // Calcular posición actual en B
    move->pos_b = get_position(b, move->value);

    // Calcular todos los costes
    calculate_costs(move, a, b);
}
