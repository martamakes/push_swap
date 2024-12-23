/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:14:26 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/23 23:03:07 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Main sorting function that chooses the appropriate algorithm
** based on the size of the stack
*/
void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size < 10)
		sort_small(a, b, size);
	else
	{
		index_stack(*a);
		turkish_sort(a, b);
	}
		
}

/*
** Shifts the stack until the smallest number is at the top
** Uses the most efficient rotation direction based on position
*/
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
void    move_cheapest_to_b(t_stack **a, t_stack **b)
{
    t_stack *cheapest;

    get_target_positions(*a, *b);
    get_cost(*a, *b);
    cheapest = get_cheapest(*a);
    do_rotations(a, b, cheapest);
    pb(a, b);
}

void    move_cheapest_to_a(t_stack **a, t_stack **b)
{
    t_stack *cheapest;

    get_target_positions_b(*b, *a);
    get_cost(*b, *a);
    cheapest = get_cheapest(*b);
    do_rotations(a, b, cheapest);
    pa(a, b);
}

void    turkish_sort(t_stack **a, t_stack **b)
{
    int size;
    int mid_index;

    size = stack_size(*a);
    mid_index = size / 2;
    while (size > 3)
	{
		if((*a)->index < mid_index)
		{
			pb(a, b);
			if(*b && (*b)->index < mid_index / 2)
				rb(b);
		}
		else
			ra(a);
	}
	sort_three(a);
	while(*b)
	{
		get_target_positions_b(*b, *a);
		get_cost(*b, *a);
		move_cheapest_to_a(a, b);
	}
    shift_stack(a);
}
