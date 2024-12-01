# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 15:27:20 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/01 15:27:24 by mvigara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Paths
LIBFT_PATH = ./lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
INC = -I./inc -I$(LIBFT_PATH)/inc

# Source files
SRC_DIR = src
SRC = $(SRC_DIR)/push_swap.c

# Object files
OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

# Compile libft first
$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re