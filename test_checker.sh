# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_checker.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 07:53:30 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/03 08:01:12 by mvigara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Generar 35 números aleatorios únicos entre INT_MIN y INT_MAX
ARG=$(python3 -c '
import random
numbers = random.sample(range(-2147483648, 2147483647), 100)
print(" ".join(map(str, numbers)))
')

# Ejecutar push_swap y verificar con checker
echo "Testing with: $ARG"
./push_swap $ARG | ./checker_OS $ARG

# Contar movimientos
NUM_MOVES=$(./push_swap $ARG | wc -l)
echo "Number of moves: $NUM_MOVES"