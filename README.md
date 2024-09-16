# Push_swap

## Project Overview
Push_swap is a 42 School algorithm project that challenges students to sort a stack of integers using a limited set of operations. The goal is to develop an efficient sorting algorithm that minimizes the number of operations required to sort the stack.

## Key Concepts to Learn

1. **Stack Data Structure**
   - Understanding the principles of Last-In-First-Out (LIFO) data structures.
   - Implementing and manipulating stacks in C.
   - Efficient traversal and modification of stack elements.

2. **Sorting Algorithms**
   - Analyzing various sorting algorithms and their complexities.
   - Adapting sorting algorithms to work with limited operations.
   - Optimizing sorting strategies for different input sizes.

3. **Algorithm Optimization**
   - Developing strategies to minimize the number of operations.
   - Balancing time complexity and operation count.
   - Handling edge cases and already sorted inputs efficiently.

4. **Dynamic Memory Management in C**
   - Proper allocation and deallocation of memory.
   - Preventing memory leaks and optimizing memory usage.

5. **Error Handling and Input Validation**
   - Implementing robust error checking for various input scenarios.
   - Handling edge cases like integer overflow and duplicate numbers.

6. **Modular Programming and Code Organization**
   - Structuring the project into logical components.
   - Creating reusable functions and maintaining clean code.

7. **Debugging and Testing Strategies**
   - Developing a test suite to verify algorithm correctness.
   - Utilizing debugging tools to identify and fix issues.

8. **Performance Analysis and Optimization**
   - Measuring and analyzing the algorithm's performance.
   - Identifying bottlenecks and optimizing critical sections.

9. **Command Line Argument Parsing**
   - Efficiently parsing and validating command line inputs.

10. **Makefile Creation and Usage**
    - Writing an efficient Makefile for building the project.
    - Understanding compilation flags and optimization options.

11. **Adherence to Coding Standards**
    - Following the 42 School Norm for consistent and clean code.
    - Maintaining good coding practices and style.

## Project Structure
- `push_swap`: Main program that sorts the stack.
- `checker`: Bonus program to verify the sorting operations.
- `libft`: Custom C library with utility functions.

## Getting Started
1. Clone the repository.
2. Run `make` to compile the project.
3. Execute `./push_swap [list of integers]` to see the sorting instructions.

## Structure
´´´
push_swap/
│
├── include/
│   ├── push_swap.h
│   └── checker.h (para la parte bonus)
│
├── lib/
│   └── libft/
│       ├── include/
│       │   └── libft.h
│       ├── src/
│       │   └── [archivos fuente de libft]
│       └── Makefile
│
├── src/
│   ├── push_swap/
│   │   ├── main.c
│   │   ├── parsing/
│   │   │   ├── parse_args.c
│   │   │   └── input_validation.c
│   │   ├── operations/
│   │   │   ├── swap.c
│   │   │   ├── push.c
│   │   │   ├── rotate.c
│   │   │   └── reverse_rotate.c
│   │   ├── algorithm/
│   │   │   ├── sort_small.c
│   │   │   ├── sort_large.c
│   │   │   └── optimize.c
│   │   ├── utils/
│   │   │   ├── stack_init.c
│   │   │   ├── stack_utils.c
│   │   │   └── error_handling.c
│   │   └── validation/
│   │       └── sorting_validation.c
│   │
│   └── checker/ (para la parte bonus)
│       ├── main.c
│       └── checker_utils.c
│
├── Makefile
└── README.md
´´´


## Author
mvigara-