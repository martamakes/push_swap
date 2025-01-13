/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:51:46 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/13 21:20:18 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top(t_stack **stack)
{
	int		size;
	int		min_pos;
	t_stack	*head;

	if (!stack || !*stack)
		return ;
	size = stack_size(*stack);
	head = *stack;
	min_pos = get_min_pos(head);
	if (min_pos > size / 2)
	{
		while (min_pos < size)
		{
			rra(stack);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(stack);
			min_pos--;
		}
	}
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	t_stack	*current;

	if (!a || !*a || !b || !*b)
		return ;
	current = *b;
	while (current)
	{
		update_positions(*a);
		update_positions(*b);
		find_target_positions(*b, *a, false);
		current = *b;
		while (current)
		{
			calculate_node_cost(current, stack_size(*b), stack_size(*a), false);
			current = current->next;
		}
		cheapest = get_cheapest_node(*b, true);
		do_rotations(a, b, cheapest);
		pa(a, b);
		current = *b;
	}
}

static void	move_to_b_until_three(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	t_stack	*current;

	if (!a || !*a)
		return ;
	while (stack_size(*a) > 3 && !is_sorted(*a))
	{
		update_positions(*a);
		update_positions(*b);
		find_target_positions(*a, *b, true);
		current = *a;
		while (current)
		{
			calculate_node_cost(current, stack_size(*a), stack_size(*b), true);
			current = current->next;
		}
		cheapest = get_cheapest_node(*a, false);
		do_rotations(a, b, cheapest);
		pb(a, b);
	}
}

void	sort_large(t_stack **a, t_stack **b)
{
	if (!a || !*a)
		return ;
	if (is_sorted(*a))
		return ;
	move_to_b_until_three(a, b);
	sort_three(a);
	move_b_to_a(a, b);
	move_min_to_top(a);
}