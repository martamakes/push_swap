/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:14:26 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 12:13:59 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Gets the position of the smallest number in the stack
** Returns the position (0-based index)
*/
int	get_min_pos(t_stack *stack)
{
	int		min;
	int		pos;
	int		min_pos;
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	min = INT_MAX;
	pos = 0;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

/*
** Sorts a stack of any size using an optimized algorithm
** For small stacks (size <= 3), uses sort_three
** For larger stacks, implements a more complex sorting strategy
*/
void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	size = stack_size(*stack_a);
	if (size <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	while (size > 3 && !is_sorted(*stack_a))
	{
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
}
