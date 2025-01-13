/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:50:42 by mvigara-          #+#    #+#             */
/*   Updated: 2024/01/13 10:50:42 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int		b_size;
	int		a_size;
	t_stack	*current;
	t_stack	*cheapest;

	while (*b)
	{
		update_positions(*a);
		update_positions(*b);
		find_target_positions(*b, *a, false);
		b_size = stack_size(*b);
		a_size = stack_size(*a);
		current = *b;
		while (current)
		{
			calculate_node_cost(current, b_size, a_size, false);
			current = current->next;
		}
		cheapest = get_cheapest_node(*b, true);
		do_rotations(a, b, cheapest);
		pa(a, b);
	}
}

void	return_single_node(t_stack **a, t_stack **b)
{
	int	a_size;

	if (!*b)
		return ;
	a_size = stack_size(*a);
	update_positions(*a);
	update_positions(*b);
	find_target_positions(*b, *a, false);
	if ((*b)->target_pos <= a_size / 2)
	{
		while ((*b)->target_pos-- > 0)
			ra(a);
	}
	else
	{
		while ((*b)->target_pos++ < a_size)
			rra(a);
	}
	pa(a, b);
}