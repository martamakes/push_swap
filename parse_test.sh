#!/bin/bash

# Colores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo -e "${BLUE}=== PUSH_SWAP TESTER ===${NC}\n"

# Función para imprimir sección
print_section() {
    echo -e "\n${YELLOW}=== $1 ===${NC}"
}

# Función para test con resultado esperado
test_case() {
    local command="$1"
    local expected_exit="$2"
    local description="$3"
    
    echo -e "\n${BLUE}Test:${NC} $description"
    echo -e "${BLUE}Command:${NC} $command"
    
    eval "$command" > .output 2> .error
    local exit_code=$?
    local output=$(cat .output)
    local error=$(cat .error)
    
    echo -e "${BLUE}Exit code:${NC} $exit_code"
    if [ ! -z "$output" ]; then
        echo -e "${BLUE}Output:${NC}\n$output"
    fi
    if [ ! -z "$error" ]; then
        echo -e "${BLUE}Error:${NC}\n$error"
    fi
    
    if [ $exit_code -eq $expected_exit ]; then
        echo -e "${GREEN}✓ Test passed${NC}"
    else
        echo -e "${RED}✗ Test failed${NC}"
    fi
}

# Función para test con checker
test_with_checker() {
    local args="$1"
    local description="$2"
    
    echo -e "\n${BLUE}Test:${NC} $description"
    echo -e "${BLUE}Arguments:${NC} $args"
    
    # Execute push_swap and count operations
    local operations=$(./push_swap $args | wc -l)
    echo -e "${BLUE}Number of operations:${NC} $operations"
    
    # Execute with checker
    local result=$(./push_swap $args | ./checker_OS $args)
    echo -e "${BLUE}Checker result:${NC} $result"
    
    if [ "$result" = "OK" ]; then
        echo -e "${GREEN}✓ Test passed${NC}"
    else
        echo -e "${RED}✗ Test failed${NC}"
    fi
}

# Limpieza de archivos temporales
cleanup() {
    rm -f .output .error
}
trap cleanup EXIT

# Comprobar si push_swap existe
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: push_swap not found${NC}"
    exit 1
fi

# Comprobar si checker_OS existe
if [ ! -f "./checker_OS" ]; then
    echo -e "${RED}Error: checker_OS not found${NC}"
    exit 1
fi

# Tests básicos
print_section "BASIC TESTS"
test_case "./push_swap 42" 0 "Single number"
test_case "./push_swap 0 1 2 3" 0 "Already sorted list"
test_case "./push_swap" 0 "No arguments"
test_case "./push_swap ''" 1 "Empty string"

# Tests de error
print_section "ERROR HANDLING"
test_case "./push_swap 42a" 1 "Invalid number (letter)"
test_case "./push_swap 42 42" 1 "Duplicate numbers"
test_case "./push_swap 2147483648" 1 "Number greater than INT_MAX"
test_case "./push_swap -2147483649" 1 "Number less than INT_MIN"
test_case "./push_swap a b c" 1 "All invalid arguments"
test_case "./push_swap 1 2 3 a 4" 1 "Some invalid arguments"

# Tests de formato
print_section "FORMAT TESTS"
test_case "./push_swap \"1 2 3\"" 0 "Numbers in string"
test_case "./push_swap \"1    2     3\"" 0 "Multiple spaces"
test_case "./push_wrap \"1 2\" \"3 4\" 5" 0 "Mixed format"

# Tests de límites
print_section "EDGE CASES"
test_case "./push_swap -0" 0 "Negative zero"
test_case "./push_swap +1" 0 "Positive sign"
test_case "./push_swap +42 -42" 0 "Mixed signs"
test_case "./push_swap 2147483647" 0 "INT_MAX"
test_case "./push_swap -2147483648" 0 "INT_MIN"

# Tests con checker
print_section "CHECKER TESTS"
test_with_checker "4 67 3 87 23" "Random 5 numbers"
test_with_checker "1 2 3 4 5" "Sorted 5 numbers"
test_with_checker "5 4 3 2 1" "Reverse sorted 5 numbers"

# Tests de rendimiento
print_section "PERFORMANCE TESTS"

echo -e "\n${BLUE}Testing with 100 random numbers:${NC}"
ARG=$(seq 1 100 | sort -R | tr '\n' ' ')
operations=$(./push_swap $ARG | wc -l)
echo "Number of operations: $operations"
if [ $operations -lt 700 ]; then
    echo -e "${GREEN}✓ Passed (<700 operations)${NC}"
else
    echo -e "${RED}✗ Failed (>=700 operations)${NC}"
fi

echo -e "\n${BLUE}Testing with 500 random numbers:${NC}"
ARG=$(seq 1 500 | sort -R | tr '\n' ' ')
operations=$(./push_swap $ARG | wc -l)
echo "Number of operations: $operations"
if [ $operations -lt 5500 ]; then
    echo -e "${GREEN}✓ Passed (<5500 operations)${NC}"
else
    echo -e "${RED}✗ Failed (>=5500 operations)${NC}"
fi

echo -e "\n${GREEN}Testing complete!${NC}"