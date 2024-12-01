# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 15:27:20 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/01 15:58:26 by mvigara-         ###   ########.fr        #
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
SRC = $(SRC_DIR)/main/push_swap.c \
      $(SRC_DIR)/parser/parse_args.c \
      $(SRC_DIR)/parser/parse_utils.c \
      $(SRC_DIR)/parser/parse_count.c \
      $(SRC_DIR)/error/error_handler.c \
      $(SRC_DIR)/stack/stack_init.c \
      $(SRC_DIR)/debug/print_stack.c

# Object files
OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

DIRS = main parser error stack debug
OBJ_DIRS = $(addprefix $(OBJ_DIR)/, $(DIRS))

all: $(OBJ_DIRS) $(NAME)

$(OBJ_DIRS):
	@mkdir -p $@

# Compile libft first
$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re