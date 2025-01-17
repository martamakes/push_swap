/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:53:42 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/17 10:53:42 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	is_consecutive(t_stack *current, t_stack *next)
{
	return (next->index == current->index + 1
		|| next->index <= current->index + 3);
}

static void	update_best_group(t_group *best, int start_idx, int end_idx,
	int start_pos)
{
	best->start_index = start_idx;
	best->end_index = end_idx;
	best->position = start_pos;
	best->size = end_idx - start_idx + 1;
}

t_group	find_best_group(t_stack *stack)
{
	t_group	best_group;
	t_stack	*current;
	int		pos;
	int		start_pos;
	int		start_idx;

	ft_memset(&best_group, 0, sizeof(t_group));
	pos = 0;
	current = stack;
	while (current && current->next)
	{
		start_pos = pos;
		start_idx = current->index;
		while (current->next && is_consecutive(current, current->next))
		{
			current = current->next;
			pos++;
		}
		if (current->index - start_idx + 1 >= 3
			&& current->index - start_idx + 1 > best_group.size)
			update_best_group(&best_group, start_idx, current->index, start_pos);
		current = current->next;
		pos++;
	}
	return (best_group);
}

int	get_group_rotations(int position, int size)
{
	if (position <= size / 2)
		return (position);
	return (position - size);
}
