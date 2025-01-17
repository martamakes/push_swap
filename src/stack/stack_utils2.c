/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:49:47 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/17 18:50:10 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_node_by_value(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*find_node_by_index(t_stack *stack, int index)
{
	while (stack)
	{
		if (stack->index == index)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	update_positions(t_stack *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos;
		stack = stack->next;
		pos++;
	}
}
