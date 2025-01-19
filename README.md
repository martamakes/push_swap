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
The checker program reads and executes sorting instructions and validates if they correctly sort the stack. You can use it in three ways:

1. Pipe with push_swap:
```bash
./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
```

2. Using instruction files:
```bash
# Create a file with instructions
echo -e "sa\npb\nra\npa" > test/instructions/test1.txt
# Run checker with instructions file
./checker 2 1 3 6 5 8 < test/instructions/test1.txt
```

3. Manual input:
```bash
./checker 2 1 3 6 5 8
# Type instructions one per line
sa
pb
ra
pa
# Press Ctrl+D when done
```

The checker will output:
- "OK" if the instructions sort the stack correctly
- "KO" if the stack is not sorted after executing all instructions
- "Error" if there are invalid instructions or other errors

#### Available Instructions:
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

### Test Instructions
The project includes a set of test instruction files in the `test/instructions/` directory:

```
test/instructions/
├── identity_test.txt    # Empty file for testing already sorted stacks
├── simple_test.txt      # Basic operations test
├── error_test.txt       # Invalid instructions test
└── complex_test.txt     # More complex operation sequences
```

To run tests with these instruction files:
```bash
# Test with a specific instruction file
./checker 1 2 3 4 5 < test/instructions/simple_test.txt

# Test error cases
./checker 1 2 3 4 5 < test/instructions/error_test.txt
```

## Visualizer

The project includes a Python visualizer to help understand how the sorting algorithm works. The visualizer provides a graphical representation of the stacks and their operations in real-time.

### Requirements
- Python3
- Tkinter (usually comes with Python3)

### Using the Visualizer

You can use the provided script `test_viz.sh` to easily run the visualizer with random numbers:

```bash
./test_viz.sh <number_of_values>
```

Example:
```bash
./test_viz.sh 100  # Visualize sorting of 100 random numbers
```

The visualizer interface includes:
- Left side: Visual representation of stacks A and B
- Right side: List of operations being executed
- Control buttons:
  * `<<` : Decrease speed
  * `>>` : Increase speed
  * `>` / `||` : Play/Pause
  * `R` : Reset visualization

The script will:
- Check if push_swap is compiled (and compile it if needed)
- Verify Python3 installation
- Generate random numbers in range (-1000 to 1000)
- Launch the visualizer

You can also run the visualizer directly:
```bash
python3 python_visualizer.py `ruby -e "puts (-1000..1000).to_a.shuffle[0...100].join(' ')"`
```

The visualizer is particularly useful for:
- Understanding how your algorithm works
- Debugging sorting issues
- Optimizing your sorting strategy
- Demonstrating the project

## Visualizer Author

The project includes a Python visualizer created by Emmanuel Ruaud (eruaud@student.le-101.fr) to help understand how the sorting algorithm works. This excellent tool provides a graphical representation of the stacks and their operations in real-time. Special thanks to Emmanuel for creating and sharing this valuable visualization tool with the 42 community.

## Author

mvigara- (Marta Vigara)