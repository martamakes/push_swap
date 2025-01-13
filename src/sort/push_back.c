#include "push_swap.h"

/*
** Calculate cost to bring node to top of stack
** @param stack: pointer to stack
** @param index: index of node
** @return: number of moves needed
*/
static int	calculate_cost(t_stack *stack, int index)
{
	int	size;

	size = stack_size(stack);
	if (index > size / 2)
		return (size - index);
	return (index);
}

/*
** Find target index in stack A for given value
** @param a: pointer to stack A
** @param value: value to find target for
** @return: index of target node
*/
static int	find_target_index(t_stack *a, int value)
{
	int		target_index;
	int		min_diff;
	int		min_value;
	int		i;

	target_index = 0;
	min_diff = INT_MAX;
	min_value = INT_MAX;
	i = 0;
	while (a)
	{
		if (a->value > value && a->value - value < min_diff)
		{
			min_diff = a->value - value;
			target_index = i;
		}
		if (a->value < min_value)
			min_value = a->value;
		a = a->next;
		i++;
	}
	if (min_diff == INT_MAX)
		return (find_index(a, min_value));
	return (target_index);
}

/*
** Optimize moves using rr/rrr when possible
** @param a: pointer to stack A
** @param b: pointer to stack B
** @param a_cost: pointer to A's move count
** @param b_cost: pointer to B's move count
*/
static void	optimize_moves(t_stack **a, t_stack **b, int *a_cost, int *b_cost)
{
	while (*a_cost > 0 && *b_cost > 0)
	{
		rr(a, b);
		(*a_cost)--;
		(*b_cost)--;
	}
	while (*a_cost < 0 && *b_cost < 0)
	{
		rrr(a, b);
		(*a_cost)++;
		(*b_cost)++;
	}
}

/*
** Push nodes back from stack B to A
** @param a: pointer to stack A
** @param b: pointer to stack B
*/
void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	b_index;
	int	a_index;
	int	a_cost;
	int	b_cost;
	int	total_cost;

	b_index = 0;
	while (b_index < stack_size(*b))
	{
		a_index = find_target_index(*a, get_value_at_index(*b, b_index));
		a_cost = calculate_cost(*a, a_index);
		b_cost = calculate_cost(*b, b_index);
		total_cost = a_cost + b_cost;
		optimize_moves(a, b, &a_cost, &b_cost);
		execute_remaining_moves(a, b, a_cost, b_cost);
		pa(a, b);
		b_index++;
	}
}
