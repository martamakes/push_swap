/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:53:42 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/17 10:53:42 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	do_group_rotations(t_stack **stack, int rotations)
{
	if (rotations >= 0)
		while (rotations--)
			ra(stack);
	else
		while (rotations++)
			rra(stack);
}

static void	optimize_b_order(t_stack **b, int remaining)
{
	if (*b && (*b)->next && (*b)->index > (*b)->next->index && remaining > 0)
		sb(b);
}

void	move_group_to_b(t_stack **a, t_stack **b, t_group *group)
{
	int		rotations;
	int		size;
	int		remaining;

	size = stack_size(*a);
	rotations = get_group_rotations(group->position, size);
	remaining = group->size;
	do_group_rotations(a, rotations);
	while (remaining--)
	{
		pb(a, b);
		optimize_b_order(b, remaining);
	}
}
