[Previous content...]

## Index Optimization in Turkish Sort

### Understanding Node Properties
Each node in our stacks has three key properties:
1. value: The actual number stored in the node
2. position: Current position in stack (0-based, dynamic)
3. index: Final position in sorted order (fixed once assigned)

### Index Benefits
The addition of indexes provides several optimizations:
1. O(1) comparison of relative positions in final sorted order
2. Better informed decisions about which nodes to move
3. More efficient target finding
4. Easy detection of sorted segments
5. Optimized return-to-A phase

### Core Optimizations Using Index

#### 1. Efficient Target Finding in B
```c
static t_stack	*find_target_in_b(t_stack *a_node, t_stack *b)
{
	t_stack	*target;
	t_stack	*current;

	if (!b)
		return (NULL);
	target = NULL;
	current = b;
	while (current)
	{
		if (current->index == a_node->index - 1)
		{
			target = current;
			break ;
		}
		current = current->next;
	}
	if (!target)
	{
		current = b;
		while (current)
		{
			if (!target && current->index < a_node->index)
				target = current;
			else if (current->index < a_node->index
				&& current->index > target->index)
				target = current;
			current = current->next;
		}
	}
	return (target);
}
```

Why this works:
- First tries to find perfect sequential match
- If not found, finds closest smaller index
- Maintains B in descending order naturally
- No need to compare values, just indexes

#### 2. Optimized Push Selection
```c
static t_stack	*find_optimal_push(t_stack *a, int stack_size)
{
	t_stack	*current;
	t_stack	*optimal;
	int		min_cost;
	int		weighted_cost;
	int		distance;

	min_cost = INT_MAX;
	optimal = NULL;
	current = a;
	while (current)
	{
		distance = ft_abs(current->position - current->index);
		weighted_cost = calculate_cost(current) * (1 + distance / stack_size);
		if (weighted_cost < min_cost)
		{
			min_cost = weighted_cost;
			optimal = current;
		}
		current = current->next;
	}
	return (optimal);
}
```

Optimization features:
- Considers distance from final position
- Weights cost by how far number is from target
- Prioritizes moving numbers that are most out of place

#### 3. Efficient Sort Check
```c
static int	is_index_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->index + 1 != current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}
```

Benefits:
- Only compares sequential indexes
- No need for value comparisons
- Early exit on first mismatch

#### 4. Optimized Return Strategy
```c
static t_stack	*find_target_in_a(t_stack *b_node, t_stack *a)
{
	t_stack	*target;
	t_stack	*current;

	if (!a)
		return (NULL);
	target = NULL;
	current = a;
	while (current)
	{
		if (current->index == b_node->index + 1)
		{
			target = current;
			break ;
		}
		current = current->next;
	}
	if (!target)
	{
		while (current)
		{
			if (!target && current->index > b_node->index)
				target = current;
			else if (current->index > b_node->index
				&& current->index < target->index)
				target = current;
			current = current->next;
		}
	}
	return (target);
}
```

Strategy benefits:
- Finds optimal placement point in A
- Maintains relative order
- Reduces final sorting needs

### Implementation Notes
1. Index must be assigned before sorting starts
2. Index assignment must consider full range of numbers
3. Position must be updated after every movement
4. Index never changes once assigned
5. All comparisons should prefer index over value