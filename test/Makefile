# Makefile para el tester

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I../include -I../lib/libft/inc -I./include
LIBFT = -L../lib/libft -lft

# Objetos necesarios del proyecto principal
PUSH_SWAP_OBJS = ../obj/push_swap/parsing/parse_args.o \
                 ../obj/push_swap/parsing/tokenize.o \
                 ../obj/push_swap/parsing/validate_numbers.o \
                 ../obj/push_swap/parsing/convert_numbers.o \
                 ../obj/push_swap/parsing/check_duplicates.o \
                 ../obj/push_swap/utils/free_tokens.o \
                 ../obj/push_swap/utils/stack_utils.o

# Regla para compilar el tester_parsing
tester_parsing: testers/tester_parsing.c $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDES) $(LIBFT)

# Asegúrate de que los objetos del proyecto principal estén actualizados
$(PUSH_SWAP_OBJS):
	$(MAKE) -C ..

# Limpieza
clean:
	rm -f tester_parsing

fclean: clean

re: fclean tester_parsing

.PHONY: clean fclean re