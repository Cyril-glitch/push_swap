NAME = libftprintf.a

CC = cc

LIBFTDIR = ./libft/
LIBFTPATH = ./libft/libft.a
LIBFT = libft.a

SRC = $(shell ls ./*.c)
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :  $(OBJ)
	make -C $(LIBFTDIR)
	cp $(LIBFTPATH) ./
	mv $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all
