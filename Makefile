# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marta <marta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 10:51:12 by marta             #+#    #+#              #
#    Updated: 2024/09/20 16:25:06 by marta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g
endif

SRCS = src/push_swap/main.c \
       src/push_swap/utils/stack_utils.c \
       src/push_swap/parsing/parse_args.c \
       src/push_swap/parsing/convert_numbers.c \
	   src/push_swap/parsing/check_duplicates.c \
	   src/push_swap/utils/free_tokens.c \
	   src/push_swap/parsing/tokenize.c \
	   src/push_swap/parsing/validate_numbers.c 

SRCS_NO_MAIN = $(filter-out src/push_swap/main.c, $(SRCS))

OBJDIR = obj
OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)

LIBFT = lib/libft/libft.a
LIBFT_DIR = lib/libft

INC = -I./include -I$(LIBFT_DIR)/inc

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(filter-out %.h,$^) -o $@
	@echo "\033[1;32mPush_swap compiled successfully!\033[0m"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "\033[1;34mCompiled $<\033[0m"

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJDIR)
	@echo "\033[1;31mCPush Swap Object Files Cleaned\033[0m"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "\033[1;31mExecutable Push Swap Cleaned\033[0m"

re: fclean all

# Test rules
test2:
	@$(eval ARG = $(shell shuf -i 0-100 -n 2))
	@echo "Testing with 2 numbers: $(ARG)"
	@./$(NAME) $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./$(NAME) $(ARG) | wc -l

test3:
	@$(eval ARG = $(shell shuf -i 0-100 -n 3))
	@echo "Testing with 3 numbers: $(ARG)"
	@./$(NAME) $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./$(NAME) $(ARG) | wc -l

test5:
	@$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	@echo "Testing with 5 numbers: $(ARG)"
	@./$(NAME) $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./$(NAME) $(ARG) | wc -l

test10:
	@$(eval ARG = $(shell shuf -i 0-5000 -n 10))
	@echo "Testing with 10 numbers: $(ARG)"
	@./$(NAME) $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./$(NAME) $(ARG) | wc -l

test25:
	@$(eval ARG = $(shell shuf -i 0-5000 -n 25))
	@echo "Testing with 25 numbers: $(ARG)"
	@./$(NAME) $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./$(NAME) $(ARG) | wc -l

test50:
	@$(eval ARG = $(shell shuf -i 0-5000 -n 50))
	@echo "Testing with 50 numbers: $(ARG)"
	@./$(NAME) $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./$(NAME) $(ARG) | wc -l

test100:
	@$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	@echo "Testing with 100 numbers"
	@./$(NAME) $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./$(NAME) $(ARG) | wc -l

test250:
	@$(eval ARG = $(shell shuf -i 0-5000 -n 250))
	@echo "Testing with 250 numbers"
	@./$(NAME) $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./$(NAME) $(ARG) | wc -l

test500:
	@$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	@echo "Testing with 500 numbers"
	@./$(NAME) $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./$(NAME) $(ARG) | wc -l

test1000:
	@$(eval ARG = $(shell shuf -i 0-10000 -n 1000))
	@echo "Testing with 1000 numbers"
	@./$(NAME) $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./$(NAME) $(ARG) | wc -l

tester: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(filter-out obj/push_swap/main.o, $(OBJS)) test/tester_parsing.c -o test_parsing $(INC) -L$(LIBFT_DIR) -lft

test: tester
	./tester_parsing

.PHONY: all clean fclean re test2 test3 test5 test10 test25 test50 test100 test250 test500 test1000 tester test