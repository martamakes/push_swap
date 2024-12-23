#!/usr/bin/python3

import os
import glob

def clean_file(filepath):
    with open(filepath, 'r') as file:
        lines = file.readlines()
    
    # Keep exactly 12 first lines
    header_lines = lines[:12]
    
    # Add newline after header
    new_content = ''.join(header_lines) + "\n"
    
    # Write back to file
    with open(filepath, 'w') as file:
        file.write(new_content)
    print(f"Cleaned {filepath}")

def main():
    # Get all .c files in current directory
    c_files = glob.glob("*.c")
    
    if not c_files:
        print("No .c files found in current directory")
        return
    
    for file in c_files:
        clean_file(file)
        
if __name__ == "__main__":
    main()