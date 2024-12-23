# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_viz.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 12:22:34 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/17 12:33:08 by mvigara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#!/bin/bash

# Colors (using printf for better compatibility)
RED=$(printf '\033[0;31m')
GREEN=$(printf '\033[0;32m')
BLUE=$(printf '\033[0;34m')
YELLOW=$(printf '\033[1;33m')
NC=$(printf '\033[0m')

# Function to run test with visualizer
test_with_viz() {
    local count=$1
    local description=$2
    
    printf "${YELLOW}=== Testing %s ===${NC}\n" "$description"
    
    # Generate random numbers
    NUMBERS=$(seq 1 $count | sort -R | tr '\n' ' ')
    
    # Run normal test first
    printf "${BLUE}Running performance test...${NC}\n"
    
    # Capture push_swap output and timing
    TMP_OUTPUT=$(mktemp)
    START=$(date +%s.%N)
    ./push_swap $NUMBERS > "$TMP_OUTPUT"
    END=$(date +%s.%N)
    
    # Count operations
    OPERATIONS=$(wc -l < "$TMP_OUTPUT")
    
    # Calculate time in milliseconds with bc (fixing decimal point issues)
    TIME=$(echo "scale=3; ($END - $START) * 1000" | bc | sed 's/^\./0./')
    
    # Print results
    printf "${BLUE}Operations:${NC} %d\n" "$OPERATIONS"
    printf "${BLUE}Time:${NC} %.3f ms\n" "$TIME"
    
    # Calculate operations per second using bc
    if (( $(echo "$TIME > 0" | bc -l) )); then
        OPS_PER_SEC=$(echo "scale=2; $OPERATIONS / ($TIME / 1000)" | bc)
        printf "${BLUE}Operations per second:${NC} %'.2f\n" "$OPS_PER_SEC"
    else
        printf "${BLUE}Operations per second:${NC} N/A (too fast to measure)\n"
    fi
    
    # Save the push_swap output for the visualizer
    INSTRUCTIONS=$(cat "$TMP_OUTPUT")
    
    # Run visualizer with proper error handling
    printf "${BLUE}Launching visualizer...${NC}\n"
    if command -v python3 >/dev/null 2>&1; then
        if python3 -c "import tkinter" 2>/dev/null; then
            # Launch visualizer in background
            (python3 python_visualizer.py $NUMBERS & ) 2>/dev/null
            sleep 0.5  # Give time for the visualizer to launch
        else
            printf "${RED}Error: tkinter not installed${NC}\n"
            printf "${YELLOW}Install tkinter with: sudo apt-get install python3-tk (Ubuntu/Debian)${NC}\n"
            printf "${YELLOW}or: brew install python-tk (MacOS)${NC}\n"
        fi
    else
        printf "${RED}Error: python3 not found${NC}\n"
        printf "${YELLOW}Please install python3${NC}\n"
    fi
    
    # Cleanup
    rm -f "$TMP_OUTPUT"
}

# Check if push_swap exists
if [ ! -f "./push_swap" ]; then
    printf "${RED}Error: push_swap program not found${NC}\n"
    exit 1
fi

# Check if Python visualizer exists
if [ ! -f "./python_visualizer.py" ]; then
    printf "${RED}Error: python_visualizer.py not found${NC}\n"
    exit 1
fi

# Menu with proper formatting
while true; do
    printf "\n${YELLOW}Choose test:${NC}\n"
    printf "1. Small set (5 numbers)\n"
    printf "2. Medium set (100 numbers)\n"
    printf "3. Large set (500 numbers)\n"
    printf "4. Custom size\n"
    printf "5. Exit\n"
    
    read -p "Choice: " choice
    
    case $choice in
        1) test_with_viz 5 "Small set";;
        2) test_with_viz 100 "Medium set";;
        3) test_with_viz 500 "Large set";;
        4) 
            read -p "Enter number of elements: " count
            if [[ "$count" =~ ^[0-9]+$ ]] && [ "$count" -gt 0 ]; then
                test_with_viz "$count" "Custom set"
            else
                printf "${RED}Please enter a valid positive number${NC}\n"
            fi
            ;;
        5) 
            printf "${GREEN}Goodbye!${NC}\n"
            exit 0
            ;;
        *) printf "${RED}Invalid option. Please choose 1-5${NC}\n";;
    esac
done