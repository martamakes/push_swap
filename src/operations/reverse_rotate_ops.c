/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:36:43 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/18 07:42:16 by mvigara-         ###   ########.fr       */
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
void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
	if (DEBUG)
    {
        ft_putstr_fd("After rra:\n", 1);
        print_one(*stack_a, 'A');
    }
}

/*
** rrb (reverse rotate b): Shifts down all elements of
** stack b by 1. The last element becomes the first one.
*/
void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
	if (DEBUG)
    {
        ft_putstr_fd("After rrb:\n", 1);
        print_one(*stack_b, 'B');
    }
}

/*
** rrr: rra and rrb at the same time.
*/
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
	if (DEBUG)
    {
        ft_putstr_fd("After rrr:\n", 1);
        print_stacks(*stack_a, *stack_b);
    }
}
