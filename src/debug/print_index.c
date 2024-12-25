/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:21:36 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/24 17:10:00 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_index(t_stack *stack, char stack_name)
{
	t_stack	*temp;

	if (!VISUALS)
		return ;
	temp = stack;
	print_debug_str("Stack ");
	print_debug_char(stack_name);
	print_debug_str(": ");
	while (temp)
	{
		print_debug_nbr(temp->value);
		print_debug_str("-> idx: ");
		print_debug_nbr(temp->index);
		print_debug_str("-> pos: ");
		print_debug_nbr(temp->pos);
		print_debug_str("\n");
		temp = temp->next;
		if (temp)
			print_debug_char(' ');
	}
	print_debug_str("\n");
}
