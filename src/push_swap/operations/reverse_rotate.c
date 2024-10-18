/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:12:19 by marta             #+#    #+#             */
/*   Updated: 2024/10/18 12:44:06 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack, char stack_name)
{
	t_node	*last;
	t_node	*prev;

	if (stack->size < 2)
		return ;
	last = stack->top;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	ft_printf("rr%c\n", stack_name);
}
void	rra(t_stack *a)
{
	reverse_rotate(a, 'a');
}

void	rrb(t_stack *b)
{
	reverse_rotate(b, 'b');
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 'a');
	reverse_rotate(b, 'b');
	ft_printf("rrr\n");
}
