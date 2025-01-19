/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:36:43 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/19 18:06:37 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Shifts down all elements of a stack by 1.
** The last element becomes the first one.
*/
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prelast;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	prelast = *stack;
	while (prelast->next->next)
		prelast = prelast->next;
	last = prelast->next;
	prelast->next = NULL;
	last->next = tmp;
	*stack = last;
}

/*
** rra (reverse rotate a): Shifts down all elements of
** stack a by 1. The last element becomes the first one.
*/
void	rra(t_stack **stack_a, bool print_ops)
{
	reverse_rotate(stack_a);
	if(print_ops)
    	ft_putstr_fd("rra\n", 1);
	if (VISUALS)
	{
		print_debug_str("After rra:\n");
		print_one(*stack_a, 'A');
	}
}

/*
** rrb (reverse rotate b): Shifts down all elements of
** stack b by 1. The last element becomes the first one.
*/
void	rrb(t_stack **stack_b, bool print_ops)
{
	reverse_rotate(stack_b);
	if(print_ops)
    	ft_putstr_fd("rrb\n", 1);
	if (VISUALS)
	{
		print_debug_str("After rrb:\n");
		print_one(*stack_b, 'B');
	}
}

/*
** rrr: rra and rrb at the same time.
*/
void	rrr(t_stack **stack_a, t_stack **stack_b, bool print_ops)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if(print_ops)
    	ft_putstr_fd("rrr\n", 1);
	if (VISUALS)
	{
		print_debug_str("After rrr:\n");
		print_stacks(*stack_a, *stack_b);
	}
}
