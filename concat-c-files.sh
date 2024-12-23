# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    concat-c-files.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 09:15:26 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/21 21:16:42 by mvigara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Clear screen for better visibility
clear

# Print welcome message
echo "=== C Source Files Concatenation Tool ==="
echo

# Ask for directory path
read -p "Enter the directory path to search for .c files: " search_dir

# Validate directory exists
if [ ! -d "$search_dir" ]; then
    echo "Error: Directory '$search_dir' does not exist."
    exit 1
fi

# Create output filename with timestamp
timestamp=$(date +%Y%m%d_%H%M%S)
output_file="concatenated_sources_${timestamp}.c"

# Initialize the output file with a header
echo "/* Concatenated source files from $search_dir" > "$output_file"
echo " * Generated on: $(date)" >> "$output_file"
echo " * Files included:" >> "$output_file"

# Find and list all .c files
find "$search_dir" -type f -name "*.c" | while read -r file; do
    echo " * - $file" >> "$output_file"
done
echo " */" >> "$output_file"
echo >> "$output_file"

# Concatenate all .c files
find "$search_dir" -type f -name "*.c" | sort | while read -r file; do
    echo "/* File: $file */" >> "$output_file"
    echo >> "$output_file"
    cat "$file" >> "$output_file"
    echo >> "$output_file"
    echo "/* End of $file */" >> "$output_file"
    echo >> "$output_file"
    echo "Processing: $file"
done

# Check if any files were found and processed
if [ ! -s "$output_file" ]; then
    echo "No .c files found in $search_dir"
    rm "$output_file"
    exit 1
fi

# Print completion message
echo
echo "Concatenation complete!"
echo "Output saved to: $output_file"
echo
echo "File contents:"
echo "-------------"
wc -l "$output_file" | awk '{print "Total lines:", $1}'
echo "-------------"