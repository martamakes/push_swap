/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:09:34 by marta             #+#    #+#             */
/*   Updated: 2024/10/18 12:44:12 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char stack_name)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	ft_printf("s%c\n", stack_name);
}

void	sa(t_stack *a)
{
	swap(a, 'a');
}

void	sb(t_stack *b)
{
	swap(b, 'b');
}
void	ss(t_stack *a, t_stack *b)
{
	swap(a, 'a');
	swap(b, 'b');
	ft_printf("ss\n");
}
