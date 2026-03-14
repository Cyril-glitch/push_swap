NAME = bin/push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

LIBDIR = ./libft/
LIB = ./libft/lib/libft.a

SRC = src/ft_list_utils.c \
			src/ft_parser.c \
			src/ft_push.c \
			src/ft_reverse.c \
			src/ft_rotate.c \
			src/ft_swap.c \
			src/ft_args_checker_utils.c \
			src/ft_little_sort.c \
			src/ft_big_sort.c \
			src/ft_findminmax.c \
			src/ft_target_a.c \
			src/ft_target_b.c \
			src/ft_cost.c \
			src/ft_strat.c \
			src/ft_cheap_push.c \
			src/ft_loadmoves.c \
			src/ft_upapushb.c \
			src/ft_upmin.c \
			src/ft_leavefree.c \
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
