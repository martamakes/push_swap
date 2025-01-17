# Turkish Sort Algorithm - Optimized Implementation Plan

## Overview
The Turkish sort algorithm efficiently sorts a stack using two stacks and a limited set of operations. It uses indexing to optimize decisions about which numbers to move and where to place them.

## Data Structure
Each node contains:
- value: The actual number
- index: Position in final sorted array (0 = smallest)
- pos: Current position in stack
- target_pos: Position of target node
- cost_a: Moves needed in stack A
- cost_b: Moves needed in stack B

## Algorithm Phases

first
sort 2
sort 3
if stack is under 10
```
void	sort_small(t_stack **a, t_stack **b, int size)
{
	int	mid;

	if (is_sorted(*a))
		return;
		
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else
	{
		while (size > 3 && !is_sorted(*a))
		{
			mid = size / 2;
			move_min_to_top(a, get_min_pos(*a), mid);
			if (!is_sorted(*a))
			{
				pb(a, b);
				size--;
			}		
		}
		if (!is_sorted(*a))
			sort_three(a);
		while (*b)
			pa(a, b);
	}
}
```

### Phase 1: Initial Setup
if stack is 10 or more
Index the stack (function void    index_stack(t_stack *stack) in src/stack/stack_init.c)
Look for the smallest index
	Phase 1.1.
	if the stack is mostly sorted and the smallest index is less than 10 rotations away, rotate to top, ra if its top half or rra if its bottom half.
	if its too far away just push the first node to b
	check if stack a is sorted
		if sorted
			return b node(s) to as in phase 4
		if not sorted
			repeat phase 1.1 to push a second node to b

2. If B[0] < B[1], swap B
3. If A is now sorted:
   - Return B nodes optimally
   - Finish
4. Else continue to Phase 2

### Phase 2: Moving to Stack B (Core Phase)
While A has > 3 nodes:
1. Update positions
2. For each A node:
   - Find target in B (closest smaller index)
   - if no smaller index, find the highest.
   - Calculate moves needed for A node to move to top of stack
   - Calculate moves needed for B target to move to top of stack
   - Calculate total cost
3. Choose node with lowest cost
   - Break ties with higher index
4. Execute move with optimizations:
   - Use rr/rrr when possible
		if both nodes are on top half or top bottom
			perform the rotation or reverse rotation until one or both reach top position in stack
				if the other still need to keep rotating, keep rotation until its in top position
				push a to b
				check if a is sorted.
					if not sorted keep pushing nodes to b
				if sorted
					push back nodes from b to a as in phase 4
   - Remember to Use shortest path rotations


### Phase 3: Sort Three
When 3 nodes remain in A:
sort_three (as in function void	sort_three(t_stack **stack) in src/sort/sort_small.c)
1. Find highest value position
2. If highest at top:
   - rotate_a
   - swap_a if needed
3. If highest in middle:
   - reverse_rotate_a
   - swap_a if needed
4. If highest at bottom:
   - swap_a if needed

### Phase 4: Return Phase
For each B node:
1. Find target in A (closest larger index)
if no larger index, find the smallest
2. Calculate optimal moves same way we did in phase 2, only this time tom ove the nodes from b to a.
3. Execute moves with rr/rrr optimizations
4. Push to A
5. Update positions

### Phase 5: Final Alignment
1. Find smallest index position
2. Rotate until smallest is at top:
   - Use ra if above median
   - Use rra if below median

## Optimization Points
1. Use index comparisons over value comparisons
2. Optimize combined moves (rr/rrr)
3. Track positions efficiently
4. Minimize total operations
5. Use median calculations for rotation decisions

## Performance Goals
- 3 numbers: ≤ 3 moves
- 5 numbers: ≤ 12 moves
- 100 numbers: ≤ 700 moves
- 500 numbers: ≤ 5500 moves