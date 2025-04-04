/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:20:20 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/19 18:21:30 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Moves the first element from source stack to the top
** of destination stack. Does nothing if source is empty.
*/
static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

/*
** pa (push a): Takes the first element of stack b
** and puts it at the top of stack a.
** Does nothing if b is empty.
*/
void	pa(t_stack **stack_a, t_stack **stack_b, bool print_ops)
{
	push(stack_b, stack_a);
	if (print_ops)
		ft_putstr_fd("pa\n", 1);
	if (VISUALS)
	{
		print_debug_str("After pa:\n");
		print_stacks(*stack_a, *stack_b);
	}
}

/*
** pb (push b): Takes the first element of stack a
** and puts it at the top of stack b.
** Does nothing if a is empty.
*/
void	pb(t_stack **stack_a, t_stack **stack_b, bool print_ops)
{
	push(stack_a, stack_b);
	if (print_ops)
		ft_putstr_fd("pb\n", 1);
	if (VISUALS)
	{
		print_debug_str("After pb:\n");
		print_stacks(*stack_a, *stack_b);
	}
}
