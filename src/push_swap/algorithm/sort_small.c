/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:03:03 by marta             #+#    #+#             */
/*   Updated: 2024/10/18 12:43:59 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a)
{
	int	top;
	int	middle;
	int	bottom;

	top = a->top->value;
	middle = a->top->next->value;
	bottom = a->top->next->next->value;
	if (top > middle && middle < bottom && top < bottom)
		sa(a);
	else if (top > middle && middle > bottom)
	{
		sa(a);
		rra(a);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(a);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(a);
		ra(a);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(a);
}

static void	sort_small(t_stack *a, t_stack *b)
{
	int	size;
	int	min_pos;

	size = a->size;
	if (size == 2 && a->top->value > a->top->next->value)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else
	{
		while (a->size > 3)
		{
			// Find the smallest number and push it to b
			min_pos = find_min_position(a);
			while (min_pos > 0)
			{
				ra(a);
				min_pos--;
			}
			pb(a, b);
		}
		sort_three(a);
		while (b->size > 0)
			pa(b, a);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_large(a, b);
}
