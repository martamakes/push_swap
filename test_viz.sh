#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Check if push_swap is compiled
check_push_swap() {
    if [ ! -f "push_swap" ]; then
        echo -e "${YELLOW}push_swap not found. Compiling...${NC}"
        make
        if [ $? -ne 0 ]; then
            echo -e "${RED}Error compiling push_swap${NC}"
            exit 1
        fi
        echo -e "${GREEN}push_swap compiled successfully${NC}"
    fi
}

# Check python3 installation
check_python() {
    if ! command -v python3 &> /dev/null; then
        echo -e "${RED}Python3 is not installed. Please install it to use the visualizer.${NC}"
        exit 1
    fi
}

# Check if number argument is provided and valid
check_args() {
    if [ $# -ne 1 ]; then
        echo -e "${RED}Usage: $0 <number_of_values>${NC}"
        echo "Example: $0 100"
        exit 1
    fi

    if ! [[ $1 =~ ^[0-9]+$ ]]; then
        echo -e "${RED}Please provide a valid positive number${NC}"
        exit 1
    fi
}

# Main
check_args "$@"
check_python
check_push_swap

NUM_COUNT=$1

echo -e "${GREEN}Launching visualizer with $NUM_COUNT random numbers...${NC}"
python3 python_visualizer.py `ruby -e "puts (-1000..1000).to_a.shuffle[0...$NUM_COUNT].join(' ')"`