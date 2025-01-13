
	



/*
** Turkish Sort Algorithm Implementation
**
** Phase 1 - Initial Setup & Moving to Stack B:
** 1. Push first node to stack B
check if A is sorted
if its sorted, find the closest bigger node in A to the node in B
if its in top half ra until its on top, if its on bottom half rra
push the b node
perform the rotations until node with the index 0 is on top.
END of turkish and go back to main
if not sorted
push second node from A to B
** 2. Sort these 2 nodes in B if needed (swap)
** 3. Check if A is already sorted - if yes, return nodes from B to their proper position and finish rotations as needed as before

If not sorted keep in the algorithym
**
** Phase 2 - Moving Nodes from A to B (until 3 left):
** For each node in A:
**   1. Calculate the cost of moving each node in A to top
**   2. Calculate the cost of moving each node in B to top
**   3. For each A node, find target node in B:
**      - Target is closest smaller number in B
**      - If no smaller number exists, target is biggest number in B
**   4. Calculate total cost for each A node:
**      cost_a (moves to top) + cost_b (moves target to top)
**   5. Choose A node with smallest total cost
**      - If multiple nodes have same cost, choose the biggest number
**   6. Optimize moves:
**      - If both nodes in 2nd position: do ss
**      - If both in top half (not 1st): do rr until one reaches top
**      - If both in bottom half: do rrr until one reaches top
**      - Complete remaining rotations for other node
**   7. Push node from A to B
**   8. Check if A is sorted - if yes, return B nodes (using phase 4) and finish

keep pushing from A to B with this pattern until there are only 3 nodes in A
**
** Phase 3 - Sort Last Three:
** 1. When 3 nodes remain in A, use sort_three algorithm
**
** Phase 4 - Return Nodes to A:
** For each node in B:
**   1. Calculate cost of moving each node in both stacks to top
**   2. Find target node in A (closest bigger number)
**      - If no bigger number exists, target is smallest number in A
**   3. Calculate total costs and choose cheapest move
**      - If multiple nodes have same cost, choose smaller number
**   4. Optimize moves (ss, rr, rrr) as in Phase 2
**   5. Push node from B to A
**
** Phase 5 - Final Alignment:
** 1. Rotate A until smallest number is on top
**
** Important Checks:
** - After each major move, check if stack A is sorted
** - Before complex operations, verify both stacks exist and have nodes
*/



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
1. Index must be assigned before sorting larger stacks starts
2. Index assignment must consider full range of numbers
3. Position must be updated after every movement
4. Index never changes once assigned
5. All comparisons should prefer index over value
6. Use 42 norminette coding synthax	
	a. functions must not contain more than 25 lines
	b. files contains only 5 functions
	c. no ternaries
	d. only if and while (no for)
	e. no more than 5 variables per function
	f. only 80 chars per line