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

- `push_swap`: Main program that sorts the stack.
- `checker`: Bonus program to verify the sorting operations.
- `libft`: Custom C library with utility functions.

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

## Compilation Instructions

1. Clone the repository:
   ```
   git clone https://github.com/martamakes/push_swap.git
   cd push_swap
   ```

2. Compile the project:
   ```
   make
   ```
   This will compile both the `push_swap` program and the `libft` library.

3. To compile with debug symbols (for use with gdb or lldb):
   ```
   make DEBUG=1
   ```

4. To compile the bonus part (checker program):
   ```
   make bonus
   ```

5. Clean up object files:
   ```
   make clean
   ```

6. Remove all generated files:
   ```
   make fclean
   ```

7. Recompile everything:
   ```
   make re

## Testing

The project includes several test rules in the Makefile to evaluate the performance of the push_swap program with different input sizes. To run these tests, follow these steps:

2. Make sure you have the `checker_linux` program in the same directory as your push_swap executable. If you're on a different operating system, you may need to use a different checker (e.g., `checker_Mac` for macOS).

3. To run a specific test, use the `make` command followed by the test name. For example:

Available test commands:
- `make test2` (2 random numbers)
- `make test3` (3 random numbers)
- `make test5` (5 random numbers)
- `make test10` (10 random numbers)
- `make test25` (25 random numbers)
- `make test50` (50 random numbers)
- `make test100` (100 random numbers)
- `make test250` (250 random numbers)
- `make test500` (500 random numbers)
- `make test1000` (1000 random numbers)

4. Each test will generate a set of random numbers, run push_swap with these numbers, pipe the output to the checker program, and display the result along with the number of instructions used.

5. To run all tests sequentially, you can use:
´´´
make test2 test3 test5 test10 test25 test50 test100 test250 test500 test1000
´´´
Note: These tests use the `shuf` command to generate random numbers, which is typically available on Linux systems. If you're using a different operating system (like macOS) that doesn't have `shuf`, you may need to modify the Makefile to use an alternative method for generating random numbers.


   ```

## Dependencies
- gcc or clang compiler
- GNU Make

## Usage
- To run push_swap:
  ```
  ./push_swap [list of integers]
  ```
- To use checker (bonus part):
  ```
  ./push_swap [list of integers] | ./checker [list of integers]
  ```


##Pseudcódigo

función main(argc, argv):
    si argc < 2:
        retornar 0  // No hay números para ordenar

    // Inicialización
    stack_a = NULL
    stack_b = NULL

    // Parsing y validación de argumentos
    números = parse_args(argv)
    si no es válido números:
        imprimir "Error" en stderr
        liberar memoria
        retornar 1

    // Inicialización de stacks
    stack_a = init_stack(números)
    si falla init_stack:
        imprimir "Error" en stderr
        liberar memoria
        retornar 1

    // Ordenación
    si no está_ordenado(stack_a):
        sort(stack_a, stack_b)

    // Limpieza y finalización
    free_stacks(stack_a, stack_b)
    retornar 0

función parse_args(argv):
    lista_números = []
    para cada arg en argv:
        si no es_número_válido(arg):
            retornar NULL
        número = convertir_a_entero(arg)
        si número está en lista_números:
            retornar NULL  // Número duplicado
        añadir número a lista_números
    retornar lista_números

función init_stack(números):
    stack = crear_stack_vacío()
    para cada número en números:
        crear_nodo(número)
        añadir_nodo_a_stack(stack, nodo)
    retornar stack

función está_ordenado(stack):
    nodo_actual = stack.top
    mientras nodo_actual.siguiente no es NULL:
        si nodo_actual.valor > nodo_actual.siguiente.valor:
            retornar falso
        nodo_actual = nodo_actual.siguiente
    retornar verdadero

función sort(stack_a, stack_b):
    si tamaño(stack_a) == 2:
        si stack_a.top.valor > stack_a.top.siguiente.valor:
            sa(stack_a)
    sino si tamaño(stack_a) == 3:
        sort_three(stack_a)
    sino si tamaño(stack_a) <= 5:
        sort_five(stack_a, stack_b)
    sino:
        turk_sort(stack_a, stack_b)

función sort_three(stack):
    a = stack.top.valor
    b = stack.top.siguiente.valor
    c = stack.top.siguiente.siguiente.valor
    
    si a > b y b < c y a < c:
        sa(stack)
    sino si a > b y b > c:
        sa(stack)
        rra(stack)
    sino si a > b y b < c y a > c:
        ra(stack)
    sino si a < b y b > c y a < c:
        sa(stack)
        ra(stack)
    sino si a < b y b > c y a > c:
        rra(stack)

función sort_five(stack_a, stack_b):
    mientras tamaño(stack_a) > 3:
        índice_mínimo = encontrar_índice_mínimo(stack_a)
        mientras índice_mínimo > 0:
            ra(stack_a)
            índice_mínimo--
        pb(stack_a, stack_b)
    
    sort_three(stack_a)
    
    mientras tamaño(stack_b) > 0:
        pa(stack_b, stack_a)

función turk_sort(stack_a, stack_b):
    tamaño = tamaño(stack_a)
    mediana = encontrar_mediana(stack_a)
    
    // Fase 1: Dividir en dos partes
    para i de 1 hasta tamaño:
        si stack_a.top.valor < mediana:
            pb(stack_a, stack_b)
        sino:
            ra(stack_a)
    
    // Fase 2: Ordenar la mitad superior en A
    mientras tamaño(stack_a) > tamaño/2 + 1:
        índice_máximo = encontrar_índice_máximo(stack_a)
        mientras índice_máximo > 0:
            ra(stack_a)
            índice_máximo--
        pb(stack_a, stack_b)
    
    // Fase 3: Insertar elementos de B en A
    mientras tamaño(stack_b) > 0:
        índice_óptimo = encontrar_índice_inserción(stack_a, stack_b.top.valor)
        mientras índice_óptimo > 0:
            ra(stack_a)
            índice_óptimo--
        pa(stack_b, stack_a)
    
    // Fase 4: Rotación final para ordenar completamente
    índice_mínimo = encontrar_índice_mínimo(stack_a)
    mientras índice_mínimo > 0:
        ra(stack_a)
        índice_mínimo--

función encontrar_mediana(stack):
    // Implementar algoritmo para encontrar la mediana

función encontrar_índice_mínimo(stack):
    // Implementar búsqueda del índice del valor mínimo

función encontrar_índice_máximo(stack):
    // Implementar búsqueda del índice del valor máximo

función encontrar_índice_inserción(stack, valor):
    // Implementar búsqueda del índice óptimo para insertar un valor

// Operaciones básicas
función sa(stack_a):
    // Intercambiar los dos primeros elementos de stack_a

función sb(stack_b):
    // Intercambiar los dos primeros elementos de stack_b

función ss(stack_a, stack_b):
    sa(stack_a)
    sb(stack_b)

función pa(stack_b, stack_a):
    // Mover el primer elemento de B al tope de A

función pb(stack_a, stack_b):
    // Mover el primer elemento de A al tope de B

función ra(stack_a):
    // Rotar stack_a hacia arriba

función rb(stack_b):
    // Rotar stack_b hacia arriba

función rr(stack_a, stack_b):
    ra(stack_a)
    rb(stack_b)

función rra(stack_a):
    // Rotar stack_a hacia abajo

función rrb(stack_b):
    // Rotar stack_b hacia abajo

función rrr(stack_a, stack_b):
    rra(stack_a)
    rrb(stack_b)

## Author
mvigara-
