/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:48:42 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/17 07:41:24 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
