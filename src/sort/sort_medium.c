/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:19:17 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/15 06:16:10 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    first_to_b(t_stack *a, t_stack *b)
{
    int i;

    ft_printf("\n=== Moviendo primeros 3 números a B ===\n");
    i = 0;
    while (i < 3 && a->size > 3)
    {
        ft_printf("Moviendo %d a B\n", a->top->value);
        pb(a, b);
        i++;
    }
    if (b->size == 3)
    {
        ft_printf("Ordenando 3 números en B: ");
        simple_print_stack(b, "B");
        sort_three(b, 'b');
        ft_printf("Después de ordenar: ");
        simple_print_stack(b, "B");
    }
    else if (b->size == 2 && b->top->value < b->top->next->value)
    {
        ft_printf("Swapping 2 números en B\n");
        sb(b);
    }
}

void    sort_medium(t_stack *a, t_stack *b)
{
    if (!a || !b || a->size <= 5)
        return ;
    
    ft_printf("\n=== Estado inicial ===\n");
    simple_print_stack(a, "A");
    simple_print_stack(b, "B");
    
    ft_printf("\n=== Fase 1: Moviendo números iniciales a B ===\n");
    first_to_b(a, b);
    
    ft_printf("\n=== Fase 2: Moviendo resto a B ===\n");
    while (a->size > 3)
    {
        ft_printf("Estado actual antes de push:\n");
        simple_print_stack(a, "A");
        simple_print_stack(b, "B");
        push_back(b, a);
    }
    
    ft_printf("\n=== Fase 3: Ordenando 3 números en A ===\n");
    simple_print_stack(a, "A");
    sort_three(a, 'a');
    
    ft_printf("\n=== Fase 4: Devolviendo números de B a A ===\n");
    push_back(a, b);
    
    ft_printf("\n=== Fase 5: Rotando hasta el mínimo ===\n");
    rotate_to_min(a);
    
    ft_printf("\n=== Estado final ===\n");
    simple_print_stack(a, "A");
}
