/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:03:03 by marta             #+#    #+#             */
/*   Updated: 2024/10/18 18:22:03 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:03:03 by marta             #+#    #+#             */
/*   Updated: 2024/10/18 18:13:59 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		sa(stack);
}

static void	sort_three_helper(t_stack *stack, int a, int b, int c)
{
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || stack->size < 2)
		return ;
	a = stack->top->value;
	b = stack->top->next->value;
	if (stack->size == 2)
	{
		sort_two(stack);
		return ;
	}
	c = stack->top->next->next->value;
	sort_three_helper(stack, a, b, c);
}

static void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = find_min_position(a);
	while (min_pos > 0)
	{
		ra(a);
		min_pos--;
	}
	pb(a, b);
}

static void	sort_small(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else
	{
		while (a->size > 3)
			push_smallest_to_b(a, b);
		sort_three(a);
		while (b->size > 0)
			pa(b, a);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_large(a, b);
}
