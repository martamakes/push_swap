# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 15:27:20 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/15 05:40:35 by mvigara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Project name
NAME = push_swap

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_DIR = lib

# Source files
# Source files
MAIN_SRC = main/push_swap.c
STACK_SRC = stack/stack_init.c stack/stack_utils.c
PARSER_SRC = parser/parse_args.c parser/parse_utils.c parser/parse_list.c
ERROR_SRC = error/error_handler.c
DEBUG_SRC = debug/print_stack.c debug/test_ops.c
OPS_SRC = operations/basic_ops.c operations/push_ops.c operations/rotate_ops.c \
    operations/reverse_rotate_ops.c
SORT_SRC = sort/sort_large.c sort/sort_small.c sort/sort_utils.c \
    sort/chunk_utils.c sort/move_utils.c sort/position_utils.c sort/sort_medium.c \
	sort/push_back.c sort/move_to_b.c
	

# Source files with directory prefix
SRCS = $(addprefix $(SRC_DIR)/, $(MAIN_SRC) $(STACK_SRC) $(PARSER_SRC) $(ERROR_SRC) $(DEBUG_SRC) $(OPS_SRC) $(SORT_SRC))
# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Libft
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)/inc

# Detect OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)    # macOS
    CFLAGS += -fsanitize=address -g
    $(info $(CYAN)Compiling for macOS with Address Sanitizer$(RESET))
else ifeq ($(UNAME_S),Linux)    # Linux
    CFLAGS += -g
    $(info $(CYAN)Compiling for Linux. Use valgrind for memory checks$(RESET))
endif

# Rules
all: $(NAME)

# Create directories
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile libft
$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)

# Link everything
$(NAME): $(LIBFT) $(OBJS)
	@echo "$(GREEN)Linking $@...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)Build complete! 🚀$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Cleaning everything...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

# Debug rule
debug: CFLAGS += -g
debug: re
	@echo "$(YELLOW)Debug build complete!$(RESET)"

# Testing helper
test: $(NAME)
	@echo "$(MAGENTA)Running basic tests...$(RESET)"
	@./$(NAME) 42
	@./$(NAME) 0 1 2 3
	@./$(NAME) 0 1 2 3 4 5 6 7 8 9
	@./$(NAME) "1 2 3"
	@./$(NAME) 0 one 2 3

.PHONY: all clean fclean re debug test

# Help message
help:
	@echo "$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)     : Build the project"
	@echo "  $(GREEN)clean$(RESET)   : Remove object files"
	@echo "  $(GREEN)fclean$(RESET)  : Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)      : Rebuild the project"
	@echo "  $(GREEN)debug$(RESET)   : Build with debug symbols"
	@echo "  $(GREEN)test$(RESET)    : Run basic tests"
	@echo
	@echo "$(CYAN)OS Detection:$(RESET)"
	@echo "  Current OS: $(UNAME_S)"
	@if [ "$(UNAME_S)" = "Darwin" ]; then \
		echo "  $(YELLOW)Using Address Sanitizer for memory checks$(RESET)"; \
	else \
		echo "  $(YELLOW)Use valgrind for memory checks$(RESET)"; \
	fi