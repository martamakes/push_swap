# Debug Mode Documentation

## Enabling Debug Mode
There are two ways to enable debug mode:

1. `make DEBUG_PRINTS=1`  
   Enables debug print statements

2. `make debug`  
   Enables debug symbols and additional debug features

## Debug Functionality
When debug mode is enabled:
- Stack information is printed
- Indexes are printed
- Additional debug information is displayed

This helps visualize and debug the sorting algorithm's behavior.

## Debug Source Files
The debug functionality is implemented in:
- `src/debug/print_stacks.c`
- `src/debug/print_index.c`

## Maintaining Debug Functionality
When updating or adding functions:
1. Keep the debug source files
2. Maintain the DEBUG_PRINTS and DEBUG flags in Makefile
3. Include debug print statements in new functions when DEBUG_PRINTS is enabled
