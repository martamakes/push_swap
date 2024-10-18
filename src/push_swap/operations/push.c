/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:10:42 by marta             #+#    #+#             */
/*   Updated: 2024/10/18 12:44:03 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dst, char dst_name)
{
	t_node	*node;

	if (src->size == 0)
		return ;
	node = src->top;
	src->top = src->top->next;
	src->size--;
	node->next = dst->top;
	dst->top = node;
	dst->size++;
	ft_printf("p%c\n", dst_name);
}
void	pa(t_stack *b, t_stack *a)
{
	push(b, a, 'a');
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b, 'b');
}
