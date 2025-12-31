NAME = bin/push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBDIR = ./ft_printf/
LIB = ./ft_printf/lib/libftprintf.a

SRC = $(wildcard scr/*.c)
 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(LIB) $(OBJ) -o $(NAME)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ)
	make clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBDIR)

re: fclean all
