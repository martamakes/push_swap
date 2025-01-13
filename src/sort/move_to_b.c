#include "push_swap.h"

static void	rotate_to_target(t_stack **a, int target_index, int a_size)
{
	if (target_index <= a_size / 2)
	{
		while (target_index-- > 0)
			ra(a);
	}
	else
	{
		while (target_index++ < a_size)
			rra(a);
	}
}

static int	find_closest_bigger(t_stack *a, int b_value)
{
	int		closest_bigger;
	int		target_index;
	int		i;
	t_stack	*current;

	closest_bigger = INT_MAX;
	target_index = 0;
	i = 0;
	current = a;
	while (current)
	{
		if (current->value > b_value && current->value < closest_bigger)
		{
			closest_bigger = current->value;
			target_index = i;
		}
		current = current->next;
		i++;
	}
	return (target_index);
}

void		return_single_node(t_stack **a, t_stack **b)
{
	int	target_index;
	int	a_size;

	a_size = stack_size(*a);
	target_index = find_closest_bigger(*a, (*b)->value);
	rotate_to_target(a, target_index, a_size);
	pa(a, b);
}

static int	calculate_cost(t_stack *stack, int index, int size)
{
	if (index <= size / 2)
		return index;
	return size - index;
}

static void	optimize_moves(t_stack **a, t_stack **b, int a_cost, int b_cost)
{
	while (a_cost > 0 && b_cost > 0)
	{
		if (a_cost <= stack_size(*a) / 2 && b_cost <= stack_size(*b) / 2)
			rr(a, b);
		else if (a_cost > stack_size(*a) / 2 && b_cost > stack_size(*b) / 2)
			rrr(a, b);
		else
			break;
		a_cost--;
		b_cost--;
	}
}

static void	move_cheapest_to_b(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		a_size = stack_size(*a);
	int		b_size = stack_size(*b);
	int		min_cost = INT_MAX;
	int		best_index = 0;
	int		a_cost, b_cost, total_cost;
	int		target_index;

	current = *a;
	for (int i = 0; current; i++)
	{
		a_cost = calculate_cost(*a, i, a_size);
		target_index = find_target_in_b(*b, current->value);
		b_cost = calculate_cost(*b, target_index, b_size);
		total_cost = a_cost + b_cost;
		
		if (total_cost < min_cost || 
			(total_cost == min_cost && current->value > (*a)->value))
		{
			min_cost = total_cost;
			best_index = i;
		}
		current = current->next;
	}
	
	a_cost = calculate_cost(*a, best_index, a_size);
	target_index = find_target_in_b(*b, (*a)->value);
	b_cost = calculate_cost(*b, target_index, b_size);
	
	optimize_moves(a, b, a_cost, b_cost);
	
	while (a_cost-- > 0)
	{
		if (best_index <= a_size / 2)
			ra(a);
		else
			rra(a);
	}
	
	while (b_cost-- > 0)
	{
		if (target_index <= b_size / 2)
			rb(b);
		else
			rrb(b);
	}
	
	pb(a, b);
}

static void	initial_setup(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	if ((*b)->value < (*b)->next->value)
		sb(b);
}

static void	final_alignment(t_stack **a)
{
	while ((*a)->value != find_min_value(*a))
	{
		if (find_min_index(*a) <= stack_size(*a) / 2)
			ra(a);
		else
			rra(a);
	}
}

void		move_to_b(t_stack **a, t_stack **b)
{
	int	a_size;

	// Phase 1 - Initial Setup & Moving to Stack B
	initial_setup(a, b);
	if (is_sorted(*a))
	{
		pa(a, b);
		pa(a, b);
		return ;
	}

	// Phase 2 - Moving Nodes from A to B (until 3 left)
	a_size = stack_size(*a);
	while (a_size > 3 && !is_sorted(*a))
	{
		move_cheapest_to_b(a, b);
		a_size = stack_size(*a);
	}

	// Phase 3 - Sort Last Three
	if (a_size == 3)
		sort_three(a);

	// Phase 5 - Final Alignment
	final_alignment(a);
}
