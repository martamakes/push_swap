# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_checker.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 07:53:30 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/15 12:52:11 by mvigara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Colores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m'

# Detectar sistema operativo y seleccionar checker
if [[ "$OSTYPE" == "darwin"* ]]; then
    CHECKER="./checker_OS"
elif [[ "$OSTYPE" == "linux"* ]]; then
    CHECKER="./checker_linux"
else
    echo -e "${RED}Error: Unsupported operating system${NC}"
    exit 1
fi

echo -e "${BLUE}=== PUSH_SWAP TESTER ===${NC}\n"
echo -e "${BLUE}Using checker for $(uname -s)${NC}\n"

# Función para imprimir sección
print_section() {
    echo -e "\n${YELLOW}=== $1 ===${NC}"
}

# Función para test con checker
test_with_checker() {
    local args="$1"
    local description="$2"
    local operations=0
    
    echo -e "\n${BLUE}Test:${NC} $description"
    echo -e "${BLUE}Arguments:${NC} $args"
    
    # Verificar si la lista ya está ordenada
    local is_sorted=true
    local prev=""
    for num in $args; do
        if [ -n "$prev" ] && [ $num -lt $prev ]; then
            is_sorted=false
            break
        fi
        prev=$num
    done

    # Si está ordenada, no necesitamos hacer nada
    if [ "$is_sorted" = true ]; then
        echo -e "${BLUE}List is already sorted${NC}"
        echo -e "${BLUE}Number of operations:${NC} 0"
        echo -e "${GREEN}✓ Test passed (no operations needed)${NC}"
        return 0
    fi
    
    # Si no está ordenada, ejecutamos push_swap
    operations=$(./push_swap $args | wc -l)
    echo -e "${BLUE}Number of operations:${NC} $operations"
    
    # Ejecutamos con checker
    local result=$(./push_swap $args | $CHECKER $args)
    echo -e "${BLUE}Checker result:${NC} $result"
    
    if [ "$result" = "OK" ]; then
        echo -e "${GREEN}✓ Test passed${NC}"
        return $operations
    else
        echo -e "${RED}✗ Test failed${NC}"
        return 1
    fi
}

# Verificar requisitos
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: push_swap not found${NC}"
    exit 1
fi

if [ ! -f "$CHECKER" ]; then
    echo -e "${RED}Error: checker not found ($CHECKER)${NC}"
    exit 1
fi

# Verificar permisos de ejecución
if [ ! -x "$CHECKER" ]; then
    echo -e "${YELLOW}Setting execute permissions for checker...${NC}"
    chmod +x "$CHECKER"
fi

if [ ! -x "./push_swap" ]; then
    echo -e "${YELLOW}Setting execute permissions for push_swap...${NC}"
    chmod +x "./push_swap"
fi

# Menú principal
while true; do
    echo -e "\n${YELLOW}Choose an option:${NC}"
    echo "1. Test with random numbers"
    echo "2. Test with specific numbers"
    echo "3. Exit"
    read -p "Your choice (1-3): " choice

    case $choice in
        1)
            read -p "How many numbers do you want to test with? " count
            if ! [[ "$count" =~ ^[0-9]+$ ]] || [ "$count" -lt 1 ]; then
                echo -e "${RED}Please enter a valid positive number${NC}"
                continue
            fi
            ARG=$(seq 1 $count | sort -R | tr '\n' ' ')
            test_with_checker "$ARG" "Random $count numbers"
            operations=$?
            
            # Mostrar límites según el tamaño
            if [ $count -le 100 ]; then
                echo -e "\nFor $count numbers, limit is 700 operations"
                if [ $operations -lt 700 ]; then
                    echo -e "${GREEN}✓ Passed (<700 operations)${NC}"
                else
                    echo -e "${RED}✗ Failed (>=700 operations)${NC}"
                fi
            elif [ $count -le 500 ]; then
                echo -e "\nFor $count numbers, limit is 5500 operations"
                if [ $operations -lt 5500 ]; then
                    echo -e "${GREEN}✓ Passed (<5500 operations)${NC}"
                else
                    echo -e "${RED}✗ Failed (>=5500 operations)${NC}"
                fi
            fi
            ;;
        2)
            read -p "Enter the numbers separated by spaces: " numbers
            if [ -z "$numbers" ]; then
                echo -e "${RED}Please enter valid numbers${NC}"
                continue
            fi
            # Verificar que son números válidos
            if ! echo "$numbers" | grep -qE '^[-0-9 ]+$'; then
                echo -e "${RED}Please enter valid integers${NC}"
                continue
            fi
            test_with_checker "$numbers" "Custom numbers"
            ;;
        3)
            echo -e "${GREEN}Goodbye!${NC}"
            exit 0
            ;;
        *)
            echo -e "${RED}Invalid option. Please choose 1, 2 or 3${NC}"
            ;;
    esac
done
