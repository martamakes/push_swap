/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:58:45 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/25 10:59:22 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Gets total cost of moving elements to their target positions
** cost_a: moves needed in stack a
** cost_b: moves needed in stack b
*/
static int	get_rotations_needed(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (-(size - pos));
}

void	get_cost(t_stack *stack, t_stack *other)
{
	int		size_a;
	int		size_b;
	t_stack	*temp;

	size_a = stack_size(stack);
	size_b = stack_size(other);
	temp = stack;
	while (temp)
	{
		temp->cost_a = get_rotations_needed(temp->pos, size_a);
		temp->cost_b = get_rotations_needed(temp->target_pos, size_b);
		temp = temp->next;
	}
}

/*
** Updates target positions for each node in stack
** Used to determine optimal positions for moves between stacks
*/
void	get_target_positions(t_stack *a, t_stack *b)
{
	t_stack	*current_a;

	if (!a || !b)
		return ;
	update_positions(a);
	update_positions(b);
	current_a = a;
	while (current_a)
	{
		current_a->target_pos = find_target_pos_a_to_b(current_a, b);
		current_a = current_a->next;
	}
	if (VISUALS)
	{
		print_debug_str("\nTarget positions calculated:\n");
		print_stack_index(a, 'A');
		print_stack_index(b, 'B');
	}
}

/*
** Finds the element with the cheapest cost to move
** Returns the node with the lowest absolute combined cost
*/
t_stack	*get_cheapest(t_stack *stack)
{
    t_stack	*cheapest;
    t_stack	*current;
    int		lowest_cost;
    int		current_cost;

    if (!stack)
        return (NULL);
    cheapest = stack;
    lowest_cost = ft_abs(stack->cost_a) + ft_abs(stack->cost_b);
    current = stack->next;
    while (current)
    {
        current_cost = ft_abs(current->cost_a) + ft_abs(current->cost_b);
        if (current_cost < lowest_cost || 
            (current_cost == lowest_cost && current->index > cheapest->index))
        {
            lowest_cost = current_cost;
            cheapest = current;
        }
        current = current->next;
    }
    return (cheapest);
}

/*
** Updates target positions for stack b nodes moving to stack a
** Used during the return phase of the sorting algorithm
*/
void	get_target_positions_b(t_stack *b, t_stack *a)
{
	t_stack	*current;

	if (!a || !b)
		return ;
	current = b;
	update_positions(a);
	update_positions(b);
	while (current)
	{
		current->target_pos = find_target_pos_b_to_a(current, a);
		current = current->next;
	}
}
