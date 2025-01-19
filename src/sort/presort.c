/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:48:42 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/19 18:09:39 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_nearly_sorted(t_stack **a)
{
	int	min_pos;
	int	size;

	size = stack_size(*a);
	min_pos = get_min_pos(*a);
	rotate_to_position(a, min_pos, size);
}

static void	push_sequential_pair(t_stack **a, t_stack **b)
{
	pb(a, b, true);
	pb(a, b, true);
	if (*b && (*b)->index > (*b)->next->index)
		sb(b, true);
}

void	push_optimal_pair(t_stack **a, t_stack **b, int first, int second)
{
	if (first == 0)
	{
		pb(a, b, true);
		if (second == 1 && !is_sorted(*a))
		{
			pb(a, b, true);
			if (*b && (*b)->index < (*b)->next->index)
				sb(b, true);
		}
	}
	else
	{
		while (first-- > 0)
			ra(a, true);
		pb(a, b, true);
		if (!is_sorted(*a))
			pb(a, b, true);
	}
}

void	init_b_stack(t_stack **a, t_stack **b)
{
	int	size;
	int	first_pos;
	int	second_pos;

	if (!a || !*a || stack_size(*a) < 4)
		return ;
	size = stack_size(*a);
	if (count_out_of_place(*a) <= 3)
	{
		handle_nearly_sorted(a);
		return ;
	}
	first_pos = 0;
	second_pos = 0;
	find_min_candidates(*a, &first_pos, &second_pos);
	if (is_position_optimal(first_pos, size))
		push_optimal_pair(a, b, first_pos, second_pos);
	else
		push_sequential_pair(a, b);
}

void	rotate_to_position(t_stack **a, int min_pos, int size)
{
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a, true);
	}
	else
	{
		while (min_pos++ < size)
			rra(a, true);
	}
}
