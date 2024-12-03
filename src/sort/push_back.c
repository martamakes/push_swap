/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:10:45 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/03 08:21:51 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_pos(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		pos;
	int		max_pos;

	max = INT_MIN;
	pos = 0;
	max_pos = 0;
	current = stack->top;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			max_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (max_pos);
}

static void	get_rotation_directions(int pos, int size, int *rot)
{
	if (pos <= size / 2)
		*rot = pos;
	else
		*rot = -(size - pos);
}

static void	sync_rotations(t_stack *a, t_stack *b, int *rot_a, int *rot_b)
{
	while (*rot_a > 0 && *rot_b > 0)
	{
		rr(a, b);
		(*rot_a)--;
		(*rot_b)--;
	}
}

static void	sync_rev_rotations(t_stack *a, t_stack *b, int *rot_a, int *rot_b)
{
	while (*rot_a < 0 && *rot_b < 0)
	{
		rrr(a, b);
		(*rot_a)++;
		(*rot_b)++;
	}
}

static void	do_single_rotation(t_stack *s, char stack_name, int dir)
{
	if (dir > 0)
	{
		if (stack_name == 'a')
			ra(s);
		else
			rb(s);
	}
	else
	{
		if (stack_name == 'a')
			rra(s);
		else
			rrb(s);
	}
}

static void	finish_rotations(t_stack *s, char stack_name, int rot)
{
	while (rot != 0)
	{
		if (rot > 0)
		{
			do_single_rotation(s, stack_name, 1);
			rot--;
		}
		else
		{
			do_single_rotation(s, stack_name, -1);
			rot++;
		}
	}
}

static void	do_push_back(t_stack *a, t_stack *b, int rot_a, int rot_b)
{
	sync_rotations(a, b, &rot_a, &rot_b);
	sync_rev_rotations(a, b, &rot_a, &rot_b);
	finish_rotations(a, 'a', rot_a);
	finish_rotations(b, 'b', rot_b);
	pa(a, b);
}

void	push_back_optimized(t_stack *a, t_stack *b)
{
	int	pos_b;
	int	rot_a;
	int	rot_b;

	while (b->size > 0)
	{
		pos_b = get_max_pos(b);
		get_rotation_directions(pos_b, b->size, &rot_b);
		rot_a = 0;
		do_push_back(a, b, rot_a, rot_b);
	}
}
