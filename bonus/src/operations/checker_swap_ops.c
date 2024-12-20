/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:41:44 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 08:42:22 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bonus/src/operations/checker_swap_ops.c
#include "../../bonus/inc/checker.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	checker_sa(t_stack **a, t_log *log)
{
	swap(a);
	log_operation(log, "sa");
}

void	checker_sb(t_stack **b, t_log *log)
{
	swap(b);
	log_operation(log, "sb");
}

void	checker_ss(t_stack **a, t_stack **b, t_log *log)
{
	swap(a);
	swap(b);
	log_operation(log, "ss");
}
