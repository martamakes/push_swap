# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    format42.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 08:56:06 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/20 08:56:35 by mvigara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

echo "Formatting .c files (excluding libft)..."
find . -name "*.c" -not -path "./lib/libft/*" -not -path "./formatter_env/*" -exec c_formatter_42 {} \;
echo "Done!"