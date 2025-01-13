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

### Phase 1: Initial Setup
1. Push first two nodes to stack B
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
   - Calculate moves needed for A node
   - Calculate moves needed for B target
   - Calculate total cost
3. Choose node with lowest cost
   - Break ties with higher index
4. Execute move with optimizations:
   - Use rr/rrr when possible
   - Use shortest path rotations
5. Push to B
6. Check if A sorted after each push

### Phase 3: Sort Three
When 3 nodes remain in A:
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
2. Calculate optimal moves
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