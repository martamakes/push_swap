/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 07:40:54 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/17 07:40:58 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_same_rotations(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rr(a, b);
		update_positions(*a);
		update_positions(*b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		rrr(a, b);
		update_positions(*a);
		update_positions(*b);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
}

static void	do_a_rotations(t_stack **a, t_stack *cheapest)
{
	while (cheapest->cost_a > 0)
	{
		ra(a);
		update_positions(*a);
		cheapest->cost_a--;
	}
	while (cheapest->cost_a < 0)
	{
		rra(a);
		update_positions(*a);
		cheapest->cost_a++;
	}
}

static void	do_b_rotations(t_stack **b, t_stack *cheapest)
{
	while (cheapest->cost_b > 0)
	{
		rb(b);
		update_positions(*b);
		cheapest->cost_b--;
	}
	while (cheapest->cost_b < 0)
	{
		rrb(b);
		update_positions(*b);
		cheapest->cost_b++;
	}
}

void	do_rotations(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (!a || !*a || !b || !*b || !cheapest)
		return ;
	do_same_rotations(a, b, cheapest);
	do_a_rotations(a, cheapest);
	do_b_rotations(b, cheapest);
}
