/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:19:17 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/16 13:16:41 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void move_min_to_b(t_stack *stack_a)
{
    int min_pos;
    int size;

    min_pos = get_min_pos(stack_a);
    size = stack_a->size;
    while (min_pos != 0)
    {
        if (min_pos <= size / 2)
            ra(stack_a);
        else
            rra(stack_a);
        min_pos = get_min_pos(stack_a);
    }
}

static void first_to_b(t_stack *a, t_stack *b)
{
    int i;
    int target_size;

    if (!a || !b)
        return ;
    
    // Para ≤5 números, dejamos 3 en A. Para >5, dejamos solo los 3 mayores
    target_size = (a->size <= 5) ? 3 : (a->size - 3);
    i = 0;
    while (i < target_size && a->size > 3)
    {
        if (a->size <= 5)
            move_min_to_b(a);
        pb(a, b);
        i++;
    }
    
    // Para 5 números, optimizamos B si es necesario
    if (b && b->size == 2 && b->top->value < b->top->next->value)
        sb(b);
}

void sort_medium(t_stack *a, t_stack *b)
{
    if (!a || !b)
        return ;

    // Primero movemos números a B dejando 3 en A
    first_to_b(a, b);

    // Ordenamos los 3 números en A
    sort_three(a, 'a');

    // Para ≤5 números usamos una estrategia simple
    if (a->size <= 5)
    {
        while (b && b->size > 0)
            pa(a, b);
    }
    else
    {
        // Para >5 números usamos push_back optimizado
        push_back(a, b);
    }

    // Aseguramos que el mínimo quede arriba
    rotate_to_min(a);
}
