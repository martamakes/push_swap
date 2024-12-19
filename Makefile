# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 15:27:20 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/19 08:58:27 by mvigara-         ###   ########.fr        #
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

# Debug prints control
DEBUG_PRINTS ?= 0

# Force recompilation when DEBUG_PRINTS changes
ifneq ($(DEBUG_PRINTS),$(shell cat $(OBJ_DIR)/.debug_prints 2>/dev/null))
FORCE_RECOMPILE := 1
endif

# Project name
NAME = push_swap

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_DIR = lib

# Source files
MAIN_SRC = main/push_swap.c

STACK_SRC = stack/stack_init.c \
           stack/stack_utils.c

PARSER_SRC = parser/parse_utils.c 

ERROR_SRC = error/error_handler.c

OPS_SRC = operations/swap_ops.c \
         operations/push_ops.c \
         operations/rotate_ops.c \
         operations/reverse_rotate_ops.c

SORT_SRC = sort/sort_small.c \
          sort/sort_large.c \
          sort/sort_utils.c \
		  sort/rotations.c \
		  sort/find_pos.c

DEBUG_SRC = debug/print_stacks.c

# Source files with directory prefix
SRCS = $(addprefix $(SRC_DIR)/, $(MAIN_SRC) $(STACK_SRC) $(PARSER_SRC) $(ERROR_SRC) $(OPS_SRC) $(SORT_SRC) $(DEBUG_SRC))

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
UNAME_M := $(shell uname -m)

# OS and Architecture specific settings
ifeq ($(UNAME_S),Darwin)    # macOS
    ifeq ($(UNAME_M),arm64)    # Apple Silicon
        CFLAGS += -g
        DEBUG_TOOL = lldb
        $(info $(CYAN)Compiling for macOS ARM64$(RESET))
    else                        # Intel Mac
        CFLAGS += -fsanitize=address -g
        LDFLAGS += -fsanitize=address
        DEBUG_TOOL = lldb
        $(info $(CYAN)Compiling for macOS Intel with Address Sanitizer$(RESET))
    endif
else ifeq ($(UNAME_S),Linux)    # Linux
    CFLAGS += -g
    DEBUG_TOOL = gdb
    $(info $(CYAN)Compiling for Linux. Use valgrind for memory checks$(RESET))
endif

# Add DEBUG flag if DEBUG=1
ifeq ($(DEBUG),1)
    CFLAGS += -DDEBUG
endif

# Rules
all: $(NAME)

# Create directories
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@
	@echo "$(DEBUG_PRINTS)" > $(OBJ_DIR)/.debug_prints

# Compile libft
$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)

# Link everything
$(NAME): $(LIBFT) $(OBJS)
	@echo "$(GREEN)Linking $@...$(RESET)"
	@$(CC) $(CFLAGS) $(if $(filter 1,$(DEBUG)),-DDEBUG=1) $(OBJS) -L$(LIBFT_DIR) -lft $(LDFLAGS) -o $(NAME)
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
debug: fclean
	@$(MAKE) DEBUG=1

# Testing helper
test: $(NAME)
	@echo "$(MAGENTA)Running basic tests...$(RESET)"
	@./$(NAME) 42
	@./$(NAME) 0 1 2 3
	@./$(NAME) 0 1 2 3 4 5 6 7 8 9
	@./$(NAME) "1 2 3"
	@./$(NAME) 0 one 2 3

.PHONY: all clean fclean re debug test help

# Help message
help:
	@echo "$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)     : Build the project"
	@echo "  $(GREEN)clean$(RESET)   : Remove object files"
	@echo "  $(GREEN)fclean$(RESET)  : Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)      : Rebuild the project"
	@echo "  $(GREEN)debug$(RESET)   : Build with debug symbols and prints enabled"
	@echo "  $(GREEN)test$(RESET)    : Run basic tests"
	@echo
	@echo "$(CYAN)Debug Options:$(RESET)"
	@echo "  make DEBUG_PRINTS=1     : Enable debug prints"
	@echo "  make debug             : Enable debug symbols and prints"
	@echo
	@echo "$(CYAN)OS Detection:$(RESET)"
	@echo "  Current OS: $(UNAME_S)"
	@if [ "$(UNAME_S)" = "Darwin" ]; then \
		echo "  $(YELLOW)Using Address Sanitizer for memory checks$(RESET)"; \
	else \
		echo "  $(YELLOW)Use valgrind for memory checks$(RESET)"; \
	fi