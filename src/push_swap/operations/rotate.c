/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:11:29 by marta             #+#    #+#             */
/*   Updated: 2024/10/18 12:44:09 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char stack_name)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("r%c\n", stack_name);
}
void	ra(t_stack *a)
{
	rotate(a, 'a');
}

void	rb(t_stack *b)
{
	rotate(b, 'b');
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, 'a');
	rotate(b, 'b');
	ft_printf("rr\n");
}
