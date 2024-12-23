# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_checker.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 07:53:30 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/23 22:17:13 by mvigara-         ###   ########.fr        #
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

# Función para evaluar número de operaciones según cantidad de números
check_operations() {
    local count=$1
    local ops=$2
    
    case $count in
        3)
            if [ $ops -le 3 ]; then
                echo -e "${GREEN}✓ Excellent! ($ops ops <= 3)${NC}"
            else
                echo -e "${RED}✗ Too many operations for 3 numbers ($ops > 3)${NC}"
            fi
            ;;
        5)
            if [ $ops -le 12 ]; then
                echo -e "${GREEN}✓ Excellent! ($ops ops <= 12)${NC}"
            else
                echo -e "${RED}✗ Too many operations for 5 numbers ($ops > 12)${NC}"
            fi
            ;;
        100)
            if [ $ops -lt 700 ]; then
                echo -e "${GREEN}✓ Perfect! 5 points ($ops < 700)${NC}"
            elif [ $ops -lt 900 ]; then
                echo -e "${YELLOW}✓ Good! 4 points ($ops < 900)${NC}"
            elif [ $ops -lt 1100 ]; then
                echo -e "${YELLOW}✓ Okay! 3 points ($ops < 1100)${NC}"
            elif [ $ops -lt 1300 ]; then
                echo -e "${YELLOW}△ Fair! 2 points ($ops < 1300)${NC}"
            elif [ $ops -lt 1500 ]; then
                echo -e "${RED}△ Poor! 1 point ($ops < 1500)${NC}"
            else
                echo -e "${RED}✗ Failed! ($ops >= 1500)${NC}"
            fi
            ;;
        500)
            if [ $ops -lt 5500 ]; then
                echo -e "${GREEN}✓ Perfect! 5 points ($ops < 5500)${NC}"
            elif [ $ops -lt 7000 ]; then
                echo -e "${YELLOW}✓ Good! 4 points ($ops < 7000)${NC}"
            elif [ $ops -lt 8500 ]; then
                echo -e "${YELLOW}✓ Okay! 3 points ($ops < 8500)${NC}"
            elif [ $ops -lt 10000 ]; then
                echo -e "${YELLOW}△ Fair! 2 points ($ops < 10000)${NC}"
            elif [ $ops -lt 11500 ]; then
                echo -e "${RED}△ Poor! 1 point ($ops < 11500)${NC}"
            else
                echo -e "${RED}✗ Failed! ($ops >= 11500)${NC}"
            fi
            ;;
        *)
            if [ $ops -lt 700 ]; then
                echo -e "${GREEN}✓ Good performance ($ops operations)${NC}"
            else
                echo -e "${YELLOW}△ Could be optimized ($ops operations)${NC}"
            fi
            ;;
    esac
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
    
    # Evaluar según número de elementos
    local num_elements=$(echo $args | wc -w)
    check_operations $num_elements $operations
    
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
    echo -e "\n${YELLOW}Choose a test option:${NC}"
    echo "1. Test with random numbers"
    echo "2. Test with simple random numbers (-249 to 250)"
    echo "3. Test with specific numbers"
    echo "4. Exit"
    read -p "Your choice (1-4): " choice

    case $choice in
        1)
            while true; do
                read -p "How many numbers do you want to test with? (or 'q' to go back): " input
                if [ "$input" = "q" ]; then
                    break
                fi
                if ! [[ "$input" =~ ^[0-9]+$ ]] || [ "$input" -lt 1 ]; then
                    echo -e "${RED}Please enter a valid positive number${NC}"
                    continue
                fi
                # Original random number generation code remains the same
                ARG=""
                count=0
                while [ $count -lt $input ]; do
                    r1=$RANDOM
                    r2=$RANDOM
                    num=$(( (r1 * 65536 + r2) % 4294967295 - 2147483648 ))
                    
                    if ! echo "$ARG" | grep -q "\b$num\b"; then
                        ARG="$ARG$num "
                        count=$((count + 1))
                    fi
                done
                test_with_checker "$ARG" "Random $input numbers"
            done
            ;;
        # Modify the random number generation part in option 2:
        2)
            while true; do
                read -p "How many numbers do you want to test with? (or 'q' to go back): " input
                if [ "$input" = "q" ]; then
                    break
                fi
                if ! [[ "$input" =~ ^[0-9]+$ ]] || [ "$input" -lt 1 ]; then
                    printf "${RED}Please enter a valid positive number${NC}\n"
                    continue
                fi

                # Generate simple random numbers between -249 and 250
                ARG=""
                declare -a numbers
                count=0
                
                # Pre-fill array with all possible numbers
                for ((i=-249; i<=250; i++)); do
                    numbers[$count]=$i
                    ((count++))
                done
                
                # Fisher-Yates shuffle and take first n numbers
                size=${#numbers[@]}
                for ((i=size-1; i>=0; i--)); do
                    j=$(($RANDOM % (i+1)))
                    # Swap elements
                    temp=${numbers[$i]}
                    numbers[$i]=${numbers[$j]}
                    numbers[$j]=$temp
                done
                
                # Take the first $input numbers
                ARG=""
                for ((i=0; i<input; i++)); do
                    ARG="$ARG${numbers[$i]} "
                done
                
                # Run push_swap and check results
                printf "\n${BLUE}Test:${NC} Simple random %d numbers (-249 to 250)\n" "$input"
                printf "${BLUE}Arguments:${NC} %s\n" "$ARG"
                
                ops=$(./push_swap $ARG | wc -l | tr -d ' ')
                printf "${BLUE}Number of operations:${NC} %d\n" "$ops"
                
                result=$(./push_swap $ARG | $CHECKER $ARG)
                printf "${BLUE}Checker result:${NC} %s\n" "$result"
                
                if [ "$result" = "OK" ]; then
                    check_operations $input $ops
                    printf "${GREEN}✓ Test passed${NC}\n"
                else
                    printf "${RED}✗ Test failed${NC}\n"
                fi
            done
            ;;
        3)
            # Previous "Test with specific numbers" option
            while true; do
                read -p "Enter the numbers separated by spaces (or 'q' to go back): " input
                if [ "$input" = "q" ]; then
                    break
                fi
                if [ -z "$input" ]; then
                    echo -e "${RED}Please enter valid numbers${NC}"
                    continue
                fi
                if ! echo "$input" | grep -qE '^[-0-9 ]+$'; then
                    echo -e "${RED}Please enter valid integers${NC}"
                    continue
                fi
                test_with_checker "$input" "Custom numbers"
            done
            ;;
        4)
            echo -e "${GREEN}Goodbye!${NC}"
            exit 0
            ;;
        *)
            echo -e "${RED}Invalid option. Please choose 1, 2, 3 or 4${NC}"
            ;;
    esac
done