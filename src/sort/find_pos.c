/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:56:36 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/25 12:38:11 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static int	get_highest_index_position(t_stack *stack)
{
    t_stack	*current;
    int		highest_index;
    int		target_pos;

    if (!stack)
        return (0);
    current = stack;
    highest_index = current->index;
    target_pos = current->pos;
    while (current)
    {
        if (current->index > highest_index)
        {
            highest_index = current->index;
            target_pos = current->pos;
        }
        current = current->next;
    }
    return (target_pos);
}*/

static int	get_lowest_pos(t_stack *stack)
{
    t_stack	*current;
    int		lowest_val;
    int		lowest_pos;

    current = stack;
    lowest_val = INT_MAX;
    lowest_pos = 0;
    while (current)
    {
        if (current->value < lowest_val)
        {
            lowest_val = current->value;
            lowest_pos = current->pos;
        }
        current = current->next;
    }
    return (lowest_pos);
}

/*static int find_closest_smaller_position(t_stack *a_node, t_stack *stack_b)
{
    t_stack *current;
    int closest_smaller_index;
    int target_pos;

    // Si B está vacío, va a la posición 0
    if (!stack_b)
        return (0);

    closest_smaller_index = INT_MIN;
    target_pos = 0;
    current = stack_b;

    // Buscamos el número más grande que sea menor que a_node
    while (current)
    {
        if (current->index < a_node->index && 
            current->index > closest_smaller_index)
        {
            closest_smaller_index = current->index;
            target_pos = current->pos;
        }
        current = current->next;
    }

    // Si no encontramos ninguno menor, va después del más grande
    if (closest_smaller_index == INT_MIN)
        return (get_highest_index_position(stack_b));

    return (target_pos);
}*/

static int find_correct_position(t_stack *a_node, t_stack *stack_b)
{
    t_stack *current;
    int highest_smaller;
    int lowest_bigger;
    int target_pos;
    
    highest_smaller = INT_MIN;
    lowest_bigger = INT_MAX;
    target_pos = 0;
    current = stack_b;
    
    // Si B está vacío
    if (!stack_b)
        return (0);
        
    // Encuentra las posiciones de los números más cercanos por arriba y por abajo
    while (current)
    {
        if (current->index < a_node->index && current->index > highest_smaller)
        {
            highest_smaller = current->index;
            target_pos = current->pos;
        }
        if (current->index > a_node->index && current->index < lowest_bigger)
            lowest_bigger = current->index;
        current = current->next;
    }
    
    // Si es el más grande, debería ir al principio
    if (a_node->index > lowest_bigger)
        return (0);
    // Si es el más pequeño, debería ir después del actual más pequeño
    if (a_node->index < highest_smaller)
        return (target_pos + 1);
    // Si está en medio, va después del número más grande que es más pequeño que él
    return (target_pos + 1);
}

int find_target_pos_a_to_b(t_stack *a_node, t_stack *stack_b)
{
    int target_pos;
    
    if (!stack_b)
        return (0);
        
    target_pos = find_correct_position(a_node, stack_b);
    
    // Asegurarse de que la posición está dentro de los límites
    if (target_pos > stack_size(stack_b))
        return (0);
        
    return (target_pos);
}

int find_closest_bigger_position(t_stack *b_node, t_stack *stack_a)
{
    t_stack *current;
    int closest_bigger_index;
    int target_pos;

    closest_bigger_index = INT_MAX;
    target_pos = 0;
    current = stack_a;
    while (current)
    {
        if (current->index > b_node->index && 
            current->index < closest_bigger_index)
        {
            closest_bigger_index = current->index;
            target_pos = current->pos;
        }
        current = current->next;
    }
    if (closest_bigger_index == INT_MAX)
        return (get_lowest_pos(stack_a));

    return (target_pos);
}
