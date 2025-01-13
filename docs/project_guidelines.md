# Push_swap Project Guidelines

## Project Overview
The push_swap project is about creating a sorting algorithm using two stacks (A and B) and a limited set of operations. The goal is to sort the numbers in stack A in ascending order using the minimum number of operations possible.

## Allowed Operations
- `sa`: Swap first two elements of stack A
- `sb`: Swap first two elements of stack B
- `ss`: sa and sb at the same time
- `pa`: Push first element from B to top of A
- `pb`: Push first element from A to top of B
- `ra`: Rotate stack A up (first element becomes last)
- `rb`: Rotate stack B up (first element becomes last)
- `rr`: ra and rb at the same time
- `rra`: Reverse rotate A (last element becomes first)
- `rrb`: Reverse rotate B (last element becomes first)
- `rrr`: rra and rrb at the same time

## Project Requirements
1. Write program in C following the Norm
2. No memory leaks allowed
3. Handle error cases properly
4. Implement Makefile with standard rules

## Algorithm Implementation (Turkish Sort)
1. Initial state: All numbers in stack A, stack B empty
2. Push first two numbers to stack B
3. For remaining numbers in A:
   - Find target position in B
   - Calculate cost of moving number
   - Push to B maintaining descending order
4. When 3 numbers remain in A:
   - Sort them directly
5. Push numbers back to A in correct order

## Performance Requirements
- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 700 operations (5 points)
- 500 numbers: ≤ 5500 operations (5 points)

## Code Structure
- Stack operations in separate files
- Error handling functions
- Algorithm implementation
- Main control flow
- Utility functions

## Error Handling
Must handle:
- Non-numeric arguments
- Numbers larger than INT_MAX/smaller than INT_MIN
- Duplicate numbers
- Empty input

## Testing
Create test cases for:
- Edge cases (MIN_INT, MAX_INT)
- Already sorted arrays
- Reverse sorted arrays
- Random number sequences
- Different sizes (3, 5, 100, 500)