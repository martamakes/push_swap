# Changelog

## [1.1.0] - 2024-01-13

### Changed
- Consolidated target finding functions into single `find_target_positions`
- Updated target position logic for both A->B and B->A movements:
  - A->B: target is closest smaller number, goes on top of biggest if none smaller
  - B->A: target is closest larger number, goes to smallest if none larger
- Updated cost calculation system with weighted costs
- Fixed edge cases in target finding
- Added better debug visualization for costs
- Simplified code structure by removing redundant functions

### Fixed
- Corrected target finding edge cases for both push directions
- Fixed position tracking in cost calculations
- Corrected pointer handling in sort_small.c
- Added missing visualization options

## [1.0.0] - Previous version