/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:10:42 by mvigara-          #+#    #+#             */
/*   Updated: 2024/01/13 11:10:42 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_costs(t_stack *stack, char stack_name)
{
	t_stack	*temp;

	if (!VISUALS)
		return ;
	temp = stack;
	print_debug_str("\nCosts for Stack ");
	print_debug_char(stack_name);
	print_debug_str(":\n");
	while (temp)
	{
		print_debug_str("Value: ");
		print_debug_nbr(temp->value);
		print_debug_str(" -> cost_a: ");
		print_debug_nbr(temp->cost_a);
		print_debug_str(" cost_b: ");
		print_debug_nbr(temp->cost_b);
		if (temp->is_cheapest)
			print_debug_str(" [CHEAPEST]");
		print_debug_char('\n');
		temp = temp->next;
	}
	print_debug_char('\n');
}

void	print_weighted_cost(t_stack *node, int weighted_cost)
{
	if (!VISUALS)
		return ;
	print_debug_str("Node value: ");
	print_debug_nbr(node->value);
	print_debug_str(" -> Base cost: ");
	print_debug_nbr(ft_abs(node->cost_a) + ft_abs(node->cost_b));
	print_debug_str(" -> Weighted cost: ");
	print_debug_nbr(weighted_cost);
	print_debug_char('\n');
}