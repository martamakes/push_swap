# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 11:01:04 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/20 11:20:26 by mvigara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = checker

MAKER = make re

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIBFT_DIR = ../lib/libft
PUSH_SWAP_EXEC = ../push_swap  # Ruta al ejecutable de push_swap

# Source files
SRC_FILES = $(SRC_DIR)/main/checker.c \
            $(SRC_DIR)/operations/checker_ops.c \
            $(SRC_DIR)/operations/checker_push_ops.c \
            $(SRC_DIR)/operations/checker_rev_rot_ops.c \
            $(SRC_DIR)/operations/checker_rotate_ops.c \
            $(SRC_DIR)/operations/checker_swap_ops.c \
            $(SRC_DIR)/utils/checker_utils.c \
            $(SRC_DIR)/debug/checker_debug.c

# Object files
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/inc

# Rules
all: check_push_swap $(NAME)

check_push_swap:
	@echo "Checking for executable at: $(PUSH_SWAP_EXEC) we are at: $(shell pwd)"
	@echo "Current directory: $(shell pwd)"
	@if [ ! -f "$(PUSH_SWAP_EXEC)" ]; then \
		echo "Error: Executable push_swap not found. Compiling push_swap..."; \
		$(MAKER) -C ../; \
		@echo "Checking again for executable at: $(PUSH_SWAP_EXEC)"; \
		if [ ! -f "$(PUSH_SWAP_EXEC)" ]; then \
			echo "Error: Failed to find push_swap executable."; \
			exit 1; \
		fi \
	fi

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(OBJ_FILES)
	@echo "Linking $@..."
	@$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "Build complete!"

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Cleaning executable..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re check_push_swap