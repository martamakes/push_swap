/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 01:17:56 by marta             #+#    #+#             */
/*   Updated: 2024/10/13 16:28:58 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

static void	add_node_to_stack(t_stack *stack, t_node *new_node)
{
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->prev = stack->top;
		stack->top->next = new_node;
		stack->top = new_node;
	}
	stack->size++;
}

static int	populate_stack(t_stack *stack, int *numbers, int count)
{
	int		i;
	t_node	*new_node;

	i = 0;
	while (i < count)
	{
		new_node = create_node(numbers[i]);
		if (!new_node)
            return (0);
		add_node_to_stack(stack, new_node);
		i++;
	}
	return (1);
}

t_stack	*init_a(int *numbers, int count)
{
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	if (!populate_stack(a, numbers, count))
	{
		free_stack(&a);
		return (NULL);
	}
	return (a);
}

t_stack	*init_b(void)
{
	t_stack	*b;

	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		return (NULL);
	b->top = NULL;
	b->bottom = NULL;
	b->size = 0;
	return (b);
}
