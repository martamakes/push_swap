# Changelog

## [2024-01-13] - Turkish Sort Algorithm Optimization

### Changed
- Optimized Turkish sort algorithm implementation
  - Improved initial B stack setup logic
  - Enhanced position finding for stack B to A transfers
  - Improved cost calculation logic

### Modified Files
1. `turk_sort.c`:
   - Separated initial B stack setup into its own function
   - Simplified main sorting loop
   - Improved readability and maintainability

2. `find_pos.c`:
   - Improved position finding logic
   - Enhanced target position calculation for both A to B and B to A transfers
   - Optimized edge case handling
   - Removed redundant code

### Fixes
1. Fixed position calculation when pushing elements to stack B
2. Improved the logic for finding target positions when moving elements back to A
3. Optimized the cost calculation for combined operations
4. Enhanced index-based positioning for better sorting efficiency

### Technical Details
- Stack B is now properly maintained in descending order
- Target position calculation now properly accounts for indices
- Position finding logic now handles edge cases better
- Code complies with 42 norm standards
- Removed redundant operations and improved efficiency

### Testing
The changes have been tested with:
- Small sets (3-5 numbers)
- Medium sets (100 numbers)
- Large sets (500 numbers)
- Edge cases (including maximum and minimum integers)
- Already sorted sequences
- Reverse sorted sequences