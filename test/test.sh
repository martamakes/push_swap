#!/bin/bash

# Get the directory where the script is located
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Go to the project root directory (one level up from the script location)
cd "$SCRIPT_DIR/.." || exit

# Check if a number argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <number_of_integers>"
    exit 1
fi

# Number of integers to generate
n=$1

# Set the directory where checkers are located (same as script directory)
CHECKER_DIR="$SCRIPT_DIR"

# Determine the OS and set appropriate commands
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    random_command="gshuf -i $INT_MIN-$INT_MAX -n $n"
    checker="${CHECKER_DIR}/checker_Mac"
elif [[ "$OSTYPE" == "linux"* ]]; then
    # Linux
    random_command="shuf -i $INT_MIN-$INT_MAX -n $n"
    checker="${CHECKER_DIR}/checker_linux"
else
    echo "Unsupported operating system"
    exit 1
fi

# Check if the appropriate checker exists
if [ ! -f "$checker" ]; then
    echo "Error: $checker not found"
    exit 1
fi

# Generate random numbers
numbers=$($random_command)

# Run push_swap and count the number of operations
operations=$(./push_swap $numbers | wc -l | tr -d ' ')

# Check if the numbers are sorted correctly
if ./push_swap $numbers | $checker $numbers | grep -q OK; then
    result="OK"
else
    result="KO"
fi

# Print the results
echo "Number of integers: $n"
echo "Number of operations: $operations"
echo "Sorted correctly: $result"

# Optionally, you can print the generated numbers
# echo "Generated numbers: $numbers"