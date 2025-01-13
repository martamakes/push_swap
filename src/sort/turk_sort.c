/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:51:45 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/25 11:06:09 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_b_stack(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	if ((*b)->index < (*b)->next->index)
		sb(b);
}

void	turkish_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 3)
		return (sort_three(a));
	init_b_stack(a, b);
	while (size > 3)
	{
		get_target_positions(*a, *b);
		get_cost(*a, *b);
		move_cheapest_to_b(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
	{
		get_target_positions_b(*b, *a);
		get_cost(*b, *a);
		move_cheapest_to_a(a, b);
	}
	shift_stack(a);
}