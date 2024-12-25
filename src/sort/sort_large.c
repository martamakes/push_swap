/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:14:26 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/25 10:34:41 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_positions(t_stack *stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = stack;
	while (current)
	{
		current->pos = i;
		i++;
		current = current->next;
	}
}

void	shift_stack(t_stack **stack)
{
	int	lowest_pos;
	int	size;

	if (!stack || !*stack)
		return ;
	size = stack_size(*stack);
	lowest_pos = get_min_pos(*stack);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rra(stack);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack);
			lowest_pos--;
		}
	}
}

void	move_cheapest_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	get_target_positions(*a, *b);
	get_cost(*a, *b);
	cheapest = get_cheapest(*a);
	do_rotations(a, b, cheapest);
	pb(a, b);
}

void	move_cheapest_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	get_target_positions_b(*b, *a);
	get_cost(*b, *a);
	cheapest = get_cheapest(*b);
	do_rotations(a, b, cheapest);
	pa(a, b);
}
