/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 07:44:17 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/17 07:44:18 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     calculate_weighted_cost(t_stack *node)
{
    int weighted_cost;

    weighted_cost = ft_abs(node->cost_a) + ft_abs(node->cost_b);
    if (VISUALS)
        print_weighted_cost(node, weighted_cost);
    return (weighted_cost);
}

t_stack *get_cheapest_node(t_stack *stack, bool ascending)
{
    t_stack *current;
    t_stack *cheapest;
    int     min_cost;
    int     current_cost;

    if (!stack)
        return (NULL);
    current = stack;
    cheapest = NULL;
    min_cost = INT_MAX;
    while (current)
    {
        current_cost = calculate_weighted_cost(current);
        if ((ascending && current->value < (cheapest ? cheapest->value : INT_MAX)) ||
            (!ascending && current->value > (cheapest ? cheapest->value : INT_MIN)))
        {
            if (current_cost < min_cost)
            {
                min_cost = current_cost;
                cheapest = current;
            }
        }
        current = current->next;
    }
    return (cheapest);
}
