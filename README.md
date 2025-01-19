# Push_swap

A sorting algorithm project from 42 School that sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions.

## Project Structure

```
.
├── inc/             # Header files
├── lib/             # Libraries
│   └── libft/       # Libft library
├── src/            
│   ├── bonus/       # Bonus program files
│   │   ├── checker_bonus.c
│   │   ├── get_next_line_bonus.c
│   │   └── process_ops_bonus.c
│   ├── debug/       # Debug utilities
│   ├── error/       # Error handling
│   ├── operations/  # Stack operations (sa, sb, ss, etc.)
│   ├── parser/      # Input parsing
│   ├── sort/        # Sorting algorithms
│   └── stack/       # Stack management
└── Makefile
```

## Compilation

### Mandatory Part
```bash
make        # Compiles push_swap program
make clean  # Removes object files
make fclean # Removes object files and executables
make re     # Recompiles the program
```

### Bonus Part
```bash
make bonus  # Compiles checker program
```

## Usage

### Push_swap
```bash
./push_swap <numbers>  # Outputs the list of operations to sort the stack
```

Example:
```bash
./push_swap 2 1 3 6 5 8
```

### Checker (Bonus)
```bash
./checker <numbers>    # Reads operations from stdin and checks if they sort the stack
```

Example:
```bash
./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
```

## Stack Operations

- `sa` - swap first two elements of stack A
- `sb` - swap first two elements of stack B
- `ss` - sa and sb at the same time
- `pa` - take first element from B and put it on top of A
- `pb` - take first element from A and put it on top of B
- `ra` - rotate stack A up by one
- `rb` - rotate stack B up by one
- `rr` - ra and rb at the same time
- `rra` - rotate stack A down by one
- `rrb` - rotate stack B down by one
- `rrr` - rra and rrb at the same time

## Debug Mode

To compile with debug prints:
```bash
make DEBUG=1
```

## Evaluation Criteria

- Less than 700 operations for 100 numbers
- Less than 5500 operations for 500 numbers

## Testing

The project includes a comprehensive testing script (`test_checker.sh`) that allows you to:

```bash
./test_checker.sh  # Run the interactive testing menu
```

The tester provides several options:
1. Test with random numbers (full INT range)
2. Test with simple random numbers (-249 to 250)
3. Test with specific numbers

Features:
- Automatic OS detection for proper checker selection
- Colored output for better readability
- Performance evaluation based on number of operations
- Interactive menu for different testing scenarios
- Integration with the official checker

The script will evaluate the performance based on the following criteria:
- For 3 numbers: ≤ 3 operations
- For 5 numbers: ≤ 12 operations
- For 100 numbers:
  * 5 points: < 700 ops
  * 4 points: < 900 ops
  * 3 points: < 1100 ops
  * 2 points: < 1300 ops
  * 1 point: < 1500 ops
- For 500 numbers:
  * 5 points: < 5500 ops
  * 4 points: < 7000 ops
  * 3 points: < 8500 ops
  * 2 points: < 10000 ops
  * 1 point: < 11500 ops

## Author

mvigara- (Marta Vigaray)