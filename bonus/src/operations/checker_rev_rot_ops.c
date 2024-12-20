/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rev_rot_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:45:03 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:39 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	checker_rra(t_stack **a, t_log *log)
{
	reverse_rotate(a);
	log_operation(log, "rra");
}

void	checker_rrb(t_stack **b, t_log *log)
{
	reverse_rotate(b);
	log_operation(log, "rrb");
}

void	checker_rrr(t_stack **a, t_stack **b, t_log *log)
{
	reverse_rotate(a);
	reverse_rotate(b);
	log_operation(log, "rrr");
}
