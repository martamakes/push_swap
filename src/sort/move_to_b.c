/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:41:28 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/17 18:41:41 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *find_cheapest_with_impact(t_stack *stack)
{
    t_stack *cheapest;
    t_stack *current;
    int lowest_net_cost;
    t_movement_impact current_impact;

    if (!stack)
        return (NULL);
    cheapest = stack;
    current = stack;
    lowest_net_cost = INT_MAX;

    while (current)
    {
        current_impact = calculate_move_impact(stack, NULL, current);
        if (current_impact.net_cost < lowest_net_cost)
        {
            lowest_net_cost = current_impact.net_cost;
            cheapest = current;
        }
        current = current->next;
    }
    return (cheapest);
}

void	move_to_b(t_stack **a, t_stack **b)
{
	int		a_size;
	int		b_size;
	t_stack	*cheapest;
	t_stack	*current;

	a_size = stack_size(*a);
	while (a_size > 3 && !is_sorted(*a))
	{
		update_positions(*a);
		update_positions(*b);
		find_target_positions(*a, *b, true);
		b_size = stack_size(*b);
		current = *a;
		while (current)
		{
			calculate_node_cost(current, a_size, b_size, true);
			current = current->next;
		}
		cheapest = find_cheapest_with_impact(*a);
		do_rotations(a, b, cheapest);
		pb(a, b);
		a_size = stack_size(*a);
	}
}
