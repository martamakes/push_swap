/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:48:42 by mvigara-          #+#    #+#             */
/*   Updated: 2024/01/13 11:48:42 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_first_node(t_stack **a, t_stack **b)
{
	int		size;

	pb(a, b);
	if (is_sorted(*a))
	{
		size = stack_size(*a);
		update_positions(*a);
		update_positions(*b);
		find_target_positions(*b, *a, false);
		if ((*b)->target_pos <= size / 2)
		{
			while ((*b)->target_pos-- > 0)
				ra(a);
		}
		else
		{
			while ((*b)->target_pos++ < size)
				rra(a);
		}
		pa(a, b);
		while ((*a)->index != 0)
		{
			if (get_min_pos(*a) <= size / 2)
				ra(a);
			else
				rra(a);
		}
	}
}

static void	init_b_stack(t_stack **a, t_stack **b)
{
	process_first_node(a, b);
	if (!*b)
		return ;
	pb(a, b);
	if ((*b)->index < (*b)->next->index)
		sb(b);
}

static void	final_alignment(t_stack **a)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	min_pos = get_min_pos(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
}

void	turkish_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 3)
		return (sort_three(a));
	init_b_stack(a, b);
	if (!*b)
		return ;
	move_to_b(a, b);
	sort_three(a);
	push_back_to_a(a, b);
	final_alignment(a);
}