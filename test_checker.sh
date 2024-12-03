# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_checker.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 07:53:30 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/03 08:36:24 by mvigara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Verificar si se proporcionó un argumento para el número de enteros
if [ $# -eq 0 ]; then
    NUM_INTS=100  # valor por defecto
else
    # Verificar que el argumento es un número positivo
    if ! [[ $1 =~ ^[0-9]+$ ]]; then
        echo -e "${RED}Error: Por favor proporciona un número positivo${NC}"
        exit 1
    fi
    NUM_INTS=$1
fi

# Detectar el sistema operativo y seleccionar el checker apropiado
if [[ "$OSTYPE" == "darwin"* ]]; then
    CHECKER="./checker_OS"
elif [[ "$OSTYPE" == "linux"* ]]; then
    CHECKER="./checker_linux"
else
    echo -e "${RED}Sistema operativo no soportado${NC}"
    exit 1
fi

# Verificar que el checker existe
if [ ! -f "$CHECKER" ]; then
    echo -e "${RED}Error: $CHECKER no encontrado${NC}"
    exit 1
fi

# Verificar que push_swap existe
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: push_swap no encontrado${NC}"
    exit 1
fi

# Generar números aleatorios únicos entre -2147483648 y 2147483647
ARG=$(python3 -c "
import random
INT_MIN = -2147483648
INT_MAX = 2147483647
try:
    numbers = random.sample(range(INT_MIN, INT_MAX + 1), $NUM_INTS)
    print(' '.join(map(str, numbers)))
except ValueError as e:
    if 'Sample larger than population' in str(e):
        print('Error: Requesting more numbers than available unique integers')
        exit(1)
    raise
")

# Verificar si Python retornó un error
if [ $? -ne 0 ]; then
    echo -e "${RED}Error generando números${NC}"
    exit 1
fi

echo -e "${YELLOW}Testing with $NUM_INTS numbers${NC}"
echo "Input: $ARG"
echo

# Ejecutar push_swap y capturar tanto la salida como el código de error
MOVES=$(./push_swap $ARG 2>&1)
PUSH_SWAP_RESULT=$?

# Verificar si push_swap se ejecutó correctamente
if [ $PUSH_SWAP_RESULT -ne 0 ]; then
    echo -e "${RED}Error: push_swap falló con código $PUSH_SWAP_RESULT${NC}"
    echo "push_swap output:"
    echo "$MOVES"
    exit 1
fi

# Si no hay movimientos, verificar si ya está ordenado
if [ -z "$MOVES" ]; then
    echo -e "${YELLOW}No movements needed - checking if already sorted${NC}"
fi

# Contar el número de movimientos
NUM_MOVES=$(echo "$MOVES" | wc -l)

# Ejecutar el checker con los movimientos y capturar su salida
echo "Checker result:"
CHECKER_OUTPUT=$(echo "$MOVES" | $CHECKER $ARG 2>&1)
CHECKER_RESULT=$?

if [ $CHECKER_RESULT -eq 0 ]; then
    echo -e "${GREEN}$CHECKER_OUTPUT${NC}"
else
    echo -e "${RED}$CHECKER_OUTPUT${NC}"
    echo "Debug info:"
    echo "push_swap movements:"
    echo "$MOVES"
fi

echo
echo -e "${YELLOW}Number of moves: $NUM_MOVES${NC}"