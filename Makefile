NAME = bin/push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBDIR = ./ft_printf/
LIB = ./ft_printf/lib/libftprintf.a

SRC = src/ft_error.c \
			src/ft_list_utils.c \
			src/ft_parser.c \
			src/ft_push.c \
			src/ft_reverse.c \
			src/ft_rotate.c \
			src/ft_swap.c \
			src/ft_args_checker_utils.c \
			src/main.c
 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ)
	make clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBDIR)

re: fclean all
