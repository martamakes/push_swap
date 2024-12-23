/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:43:51 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:55 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	checker_ra(t_stack **a, t_log *log)
{
	rotate(a);
	log_operation(log, "ra");
}

void	checker_rb(t_stack **b, t_log *log)
{
	rotate(b);
	log_operation(log, "rb");
}

void	checker_rr(t_stack **a, t_stack **b, t_log *log)
{
	rotate(a);
	rotate(b);
	log_operation(log, "rr");
}
