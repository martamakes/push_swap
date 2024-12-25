# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    format42.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 08:56:06 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/20 09:32:38 by mvigara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Colors for output (compatible with both macOS and Linux)
if [[ "$(uname)" == "Darwin" ]]; then
    # macOS specific settings
    GREEN=$'\033[0;32m'
    BLUE=$'\033[0;34m'
    RED=$'\033[0;31m'
    NC=$'\033[0m'
else
    # Linux specific settings
    GREEN='\033[0;32m'
    BLUE='\033[0;34m'
    RED='\033[0;31m'
    NC='\033[0m'
fi

# Help function
show_help() {
    echo -e "${BLUE}Usage:${NC} $0 [directories...]"
    echo
    echo "Format C (.c) and header (.h) files according to 42 norm in specified directories"
    echo
    echo -e "${BLUE}Options:${NC}"
    echo "  -h, --help     Show this help message"
    echo
    echo -e "${BLUE}Examples:${NC}"
    echo "  $0 src includes     # Format files in src and includes directories"
    echo "  $0 .               # Format all .c and .h files in current directory and subdirectories"
    echo
    echo -e "${RED}Note:${NC} c_formatter_42 must be installed in your system"
    echo "For installation:"
    echo "  macOS: python3 -m pip install c_formatter_42 --user"
    echo "  Linux: python3 -m pip install c_formatter_42 --user"
    echo "  Note: You might need to add pip bin directory to your PATH"
}

# Check if help is requested
if [[ "$1" == "-h" || "$1" == "--help" ]]; then
    show_help
    exit 0
fi

# Function to check if command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Check for c_formatter_42 in different possible locations
if ! command_exists c_formatter_42; then
    # Check in Python user base
    USER_BASE_BIN=$(python3 -m site --user-base)/bin
    if [[ -f "${USER_BASE_BIN}/c_formatter_42" ]]; then
        PATH="${USER_BASE_BIN}:${PATH}"
    else
        echo -e "${RED}Error: c_formatter_42 is not installed or not in PATH${NC}"
        echo "Please install it using:"
        echo "  python3 -m pip install c_formatter_42 --user"
        echo
        echo "Then, you might need to add this to your shell configuration file (.bashrc, .zshrc, etc.):"
        echo "  export PATH=\"\$(python3 -m site --user-base)/bin:\$PATH\""
        exit 1
    fi
fi

# If no directories specified, use current directory
if [ $# -eq 0 ]; then
    directories="."
else
    directories="$@"
fi

# Format function for both .c and .h files
format_directory() {
    local dir=$1
    local file_type=$2
    echo -e "${GREEN}Formatting ${file_type} files in ${dir}...${NC}"
    if [[ "$(uname)" == "Darwin" ]]; then
        # macOS version
        find "$dir" -type f -name "*${file_type}" -exec c_formatter_42 {} \;
    else
        # Linux version
        find "$dir" -type f -name "*${file_type}" -exec c_formatter_42 {} \;
    fi
}

# Process each directory
for dir in $directories; do
    if [ ! -d "$dir" ]; then
        echo -e "${RED}Error: Directory '$dir' does not exist${NC}"
        continue
    fi
    
    # Format both .c and .h files
    format_directory "$dir" ".c"
    format_directory "$dir" ".h"
done

echo -e "${GREEN}All formatting completed!${NC}"