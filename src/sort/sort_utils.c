/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:58:45 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/23 22:36:19 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Updates position values for all nodes in a stack
** This is crucial for cost calculations
*/
void	update_positions(t_stack *stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = stack;
	while (current)
	{
		current->pos = i;
		i++;
		current = current->next;
	}
}

/*
** Gets total cost of moving elements to their target positions
** cost_a: moves needed in stack a
** cost_b: moves needed in stack b
*/
void    get_cost(t_stack *stack, t_stack *other)
{
    int     size_a;
    int     size_b;
    t_stack *temp;

    size_a = stack_size(stack);
    size_b = stack_size(other);
    temp = stack;
    while (temp)
    {
        temp->cost_a = temp->pos;
        if (temp->pos > size_a / 2)
            temp->cost_a = -(size_a - temp->pos);
        temp->cost_b = temp->target_pos;
        if (temp->target_pos > size_b / 2)
            temp->cost_b = -(size_b - temp->target_pos);
        if ((temp->cost_a >= 0 && temp->cost_b >= 0) ||
            (temp->cost_a < 0 && temp->cost_b < 0))
        {
            if (ft_abs(temp->cost_a) > ft_abs(temp->cost_b))
                temp->cost_b = temp->cost_a;
            else
                temp->cost_a = temp->cost_b;
        }
        temp = temp->next;
    }
}

/*
** Updates target positions for each node in stack
** Used to determine optimal positions for moves between stacks
*/
void	get_target_positions(t_stack *a, t_stack *b)
{
	t_stack	*current;

	if (!a || !b)
		return ;
	current = a;
	update_positions(a);
	update_positions(b);
	while (current)
	{
		current->target_pos = find_target_pos_a_to_b(current, b);
		current = current->next;
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
	int		cost;

	if (!stack)
		return (NULL);
	cheapest = stack;
	lowest_cost = ft_abs(stack->cost_a) + ft_abs(stack->cost_b);
	current = stack->next;
	while (current)
	{
		cost = ft_abs(current->cost_a) + ft_abs(current->cost_b);
		if (cost < lowest_cost)
		{
			lowest_cost = cost;
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
