/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:33:49 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/18 08:36:37 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Shifts up all elements of a stack by 1.
** The first element becomes the last one.
*/
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = stack_last(*stack);
	tmp->next = NULL;
	last->next = tmp;
}

/*
** ra (rotate a): Shifts up all elements of stack a by 1.
** The first element becomes the last one.
*/
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
	if (VISUALS)
	{
		print_debug_str("After ra:\n");
		print_one(*stack_a, 'A');
	}
}

/*
** rb (rotate b): Shifts up all elements of stack b by 1.
** The first element becomes the last one.
*/
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
	if (VISUALS)
	{
		print_debug_str("After rb:\n");
		print_one(*stack_b, 'B');
	}
}

/*
** rr: ra and rb at the same time.
*/
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
	if (VISUALS)
	{
		print_debug_str("After pa:\n");
		print_stacks(*stack_a, *stack_b);
	}
}
