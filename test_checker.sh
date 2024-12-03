# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_checker.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 07:53:30 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/03 08:29:42 by mvigara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Verificar si se proporcionó un argumento para el número de enteros
if [ $# -eq 0 ]; then
    NUM_INTS=100  # valor por defecto
else
    # Verificar que el argumento es un número positivo
    if ! [[ $1 =~ ^[0-9]+$ ]]; then
        echo "Error: Por favor proporciona un número positivo"
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
    echo "Sistema operativo no soportado"
    exit 1
fi

# Verificar que el checker existe
if [ ! -f "$CHECKER" ]; then
    echo "Error: $CHECKER no encontrado"
    exit 1
fi

# Generar números aleatorios únicos entre INT_MIN y INT_MAX
ARG=$(python3 -c "
import random
numbers = random.sample(range(-2147483648, 2147483647), $NUM_INTS)
print(' '.join(map(str, numbers)))
")

# Ejecutar push_swap y verificar con checker
echo "Testing with $NUM_INTS numbers:"
./push_swap $ARG | $CHECKER $ARG

# Contar movimientos
NUM_MOVES=$(./push_swap $ARG | wc -l)
echo "Number of moves: $NUM_MOVES"