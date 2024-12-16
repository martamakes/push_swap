/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:19:17 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/16 13:38:14 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void move_min_to_b(t_stack *stack_a)
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
}*/

#include "push_swap.h"

static void rotate_min_to_top(t_stack *a)
{
    int min_pos;

    min_pos = get_min_pos(a);
    while (min_pos > 0)
    {
        if (min_pos <= a->size / 2)
        {
            ra(a);
            min_pos--;
        }
        else
        {
            rra(a);
            min_pos = get_min_pos(a);
        }
    }
}

void sort_medium(t_stack *a, t_stack *b)
{
    int nums_to_push;

    if (!a || !b || a->size <= 3 || is_sorted(a))
        return ;

    // Calculamos cuántos números mover a B (1 para 4 números, 2 para 5)
    nums_to_push = a->size - 3;

    // Movemos los números más pequeños a B
    while (nums_to_push > 0)
    {
        rotate_min_to_top(a);
        pb(a, b);
        nums_to_push--;
    }

    // Ordenamos los 3 restantes en A
    sort_three(a, 'a');

    // Devolvemos los números de B a A
    while (b->size > 0)
        pa(a, b);
}
