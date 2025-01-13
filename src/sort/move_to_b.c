/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:48:42 by mvigara-          #+#    #+#             */
/*   Updated: 2024/01/13 10:48:42 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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
		cheapest = get_cheapest_node(*a, false);
		do_rotations(a, b, cheapest);
		pb(a, b);
		a_size = stack_size(*a);
	}
}