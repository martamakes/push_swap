#!/bin/bash

# Remove the existing all.c if it exists
rm -f all.c

# Find all .c files in current directory and subdirectories
# and concatenate them into all.c with file headers
find . -type f -name "*.c" | while read -r file; do
    # Add a header for each file
    echo -e "\n/* ************************************************************************** */" >> all.c
    echo "/*                                                                            */" >> all.c
    echo "/*     File: $(basename "$file")" >> all.c
    echo "/*     Path: $file" >> all.c
    echo "/*                                                                            */" >> all.c
    echo "/* ************************************************************************** */" >> all.c
    echo -e "\n" >> all.c
    
    # Append the file content
    cat "$file" >> all.c
    
    # Add a newline after each file
    echo -e "\n" >> all.c
done

echo "All .c files have been concatenated into all.c"