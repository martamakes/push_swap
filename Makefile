# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 15:27:20 by mvigara-          #+#    #+#              #
#    Updated: 2025/01/19 17:49:12 by mvigara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED := $(shell printf "\033[0;31m")
GREEN := $(shell printf "\033[0;32m")
YELLOW := $(shell printf "\033[0;33m")
BLUE := $(shell printf "\033[0;34m")
MAGENTA := $(shell printf "\033[0;35m")
CYAN := $(shell printf "\033[0;36m")
WHITE := $(shell printf "\033[0;37m")
RESET := $(shell printf "\033[0m")

# Debug prints control
DEBUG_PRINTS ?= 0

# Force recompilation when DEBUG_PRINTS changes
ifneq ($(DEBUG_PRINTS),$(shell cat $(OBJ_DIR)/.debug_prints 2>/dev/null))
FORCE_RECOMPILE := 1
endif

# Project name
NAME = push_swap
CHECKER = checker

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_DIR = lib

INCLUDES = -I$(INC_DIR)  # Solo para la parte principal
CHECKER_INCLUDES = -I$(INC_DIR) -I$(CHECKER_INC_DIR)  # Para el bonus

# Source files
MAIN_SRC = main/push_swap.c

STACK_SRC = stack/stack_init.c \
           stack/stack_utils.c \
           stack/stack_utils2.c

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
          sort/find_pos.c \
          sort/turk_sort.c \
          sort/move_to_b.c \
          sort/push_back.c \
          sort/cost_utils.c \
          sort/presort.c \
          sort/presort_utils.c \
          sort/advanced_cost.c \
          sort/find_pos_utils.c 

DEBUG_SRC = debug/print_stacks.c \
            debug/print_index.c \
            debug/print_costs.c

BONUS_SRC = bonus/checker_bonus.c 

# Source files with directory prefix
SRCS = $(addprefix $(SRC_DIR)/, $(MAIN_SRC) $(STACK_SRC) $(PARSER_SRC) $(ERROR_SRC) $(OPS_SRC) $(SORT_SRC) $(DEBUG_SRC))

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CHECKER_OBJS = $(CHECKER_SRCS:$(CHECKER_SRC_DIR)/%.c=$(CHECKER_OBJ_DIR)/%.o)
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

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

bonus: $(LIBFT) $(BONUS_OBJS) $(filter-out $(OBJ_DIR)/$(MAIN_SRC:.c=.o), $(OBJS))
	@echo "$(GREEN)Building checker...$(RESET)"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) \
		$(filter-out $(OBJ_DIR)/$(MAIN_SRC:.c=.o), $(OBJS)) \
		-L$(LIBFT_DIR) -lft $(LDFLAGS) -o $(CHECKER)
	@echo "$(GREEN)Checker build complete! 🎯$(RESET)"
	
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Cleaning everything...$(RESET)"
	@rm -f $(NAME) $(CHECKER)
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

# Tools download rule
get-tools:
	@echo "$(CYAN)Downloading testing tools...$(RESET)"
	@curl -O https://raw.githubusercontent.com/martamakes/push_swap/main/test_viz.sh
	@curl -O https://raw.githubusercontent.com/martamakes/push_swap/main/test_checker.sh
	@curl -O https://raw.githubusercontent.com/martamakes/push_swap/main/python_visualizer.py
	@curl -O https://raw.githubusercontent.com/martamakes/push_swap/main/checker_OS
	@curl -O https://raw.githubusercontent.com/martamakes/push_swap/main/checker_linux
	@chmod +x test_viz.sh test_checker.sh checker_OS checker_linux
	@echo "$(GREEN)Testing tools downloaded successfully!$(RESET)"

.PHONY: all clean fclean re debug test help get-tools

# Help message
help:
	@echo "$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)     : Build the project"
	@echo "  $(GREEN)clean$(RESET)   : Remove object files"
	@echo "  $(GREEN)fclean$(RESET)  : Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)      : Rebuild the project"
	@echo "  $(GREEN)debug$(RESET)   : Build with debug symbols and prints enabled"
	@echo "  $(GREEN)test$(RESET)    : Run basic tests
	@echo "  $(GREEN)get-tools$(RESET): Download testing tools (visualizer and checker)""
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