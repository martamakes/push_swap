/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:51:46 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/15 07:58:13 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_two(t_stack *stack_a)
{
    if (!stack_a || stack_a->size != 2)
        return ;
    if (!is_sorted(stack_a))
        sa(stack_a);
}

void    sort_three(t_stack *stack_a, char c)
{
    int highest_pos;

    if (!stack_a || stack_a->size != 3)
        return ;
    if (is_sorted(stack_a))
        return ;
    highest_pos = get_max_pos(stack_a);
    if (highest_pos == 0)
    {
        rotate(stack_a);
        ft_printf("r%c\n", c);   
    }
    else if (highest_pos == 1)
    {
        reverse_rotate(stack_a);
        ft_printf("r%c\n", c);   
    }
    if (!is_sorted(stack_a))
    {
        swap_top(stack_a);
        ft_printf("s%c\n", c);   
    }
}

/*static void    push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
    int     min_pos;

    min_pos = get_min_pos(stack_a);
    while (min_pos != 0)
    {
        if (min_pos <= stack_a->size / 2)
            ra(stack_a);
        else
            rra(stack_a);
        min_pos = get_min_pos(stack_a);
    }
    pb(stack_a, stack_b);
}

void    sort_five(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b || stack_a->size > 5)
        return ;
    if (is_sorted(stack_a))
        return ;
    while (stack_a->size > 3)
        push_min_to_b(stack_a, stack_b);
    sort_three(stack_a, 'a');
    while (stack_b->size > 0)
        pa(stack_a, stack_b);
}*/

static void    push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
    int     min_pos;

    ft_printf("\n=== Buscando mínimo para enviar a B ===\n");
    simple_print_stack(stack_a, "A");
    simple_print_stack(stack_b, "B");

    min_pos = get_min_pos(stack_a);
    ft_printf("Min encontrado en posición: %d (size=%d)\n", min_pos, stack_a->size);

    // Mientras el mínimo no esté en la cima
    while (min_pos != 0)
    {
        // Si está en la primera mitad del stack
        if (min_pos <= (stack_a->size / 2))
        {
            ft_printf("ra (min_pos=%d, size=%d)\n", min_pos, stack_a->size);
            ra(stack_a);
        }
        // Si está en la segunda mitad
        else
        {
            ft_printf("rra (min_pos=%d, size=%d)\n", min_pos, stack_a->size);
            rra(stack_a);
        }
        min_pos = get_min_pos(stack_a);
    }

    ft_printf("Push a B del mínimo: %d\n", stack_a->top->value);
    pb(stack_a, stack_b);
}

void    sort_five(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b || stack_a->size > 5)
        return ;
    
    ft_printf("\n=== Inicio sort_five ===\n");
    ft_printf("Stack inicial:\n");
    simple_print_stack(stack_a, "A");

    if (is_sorted(stack_a))
    {
        ft_printf("Stack ya ordenado\n");
        return ;
    }

    ft_printf("\n=== Fase 1: Envío de números a B ===\n");
    while (stack_a->size > 3)
    {
        push_min_to_b(stack_a, stack_b);
        ft_printf("Después de push_min_to_b:\n");
        simple_print_stack(stack_a, "A");
        simple_print_stack(stack_b, "B");
    }

    ft_printf("\n=== Fase 2: Ordenar tres números en A ===\n");
    sort_three(stack_a, 'a');
    ft_printf("Después de sort_three:\n");
    simple_print_stack(stack_a, "A");

    ft_printf("\n=== Fase 3: Recuperar números de B ===\n");
    while (stack_b->size > 0)
    {
        pa(stack_a, stack_b);
        ft_printf("Después de pa:\n");
        simple_print_stack(stack_a, "A");
        simple_print_stack(stack_b, "B");
    }

    ft_printf("\n=== Estado final ===\n");
    simple_print_stack(stack_a, "A");
}

