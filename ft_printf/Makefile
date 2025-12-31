# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/31 11:46:19 by cycolonn          #+#    #+#              #
#    Updated: 2025/12/31 12:30:19 by cycolonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft/
LIBFTPATH = ./libft/lib/libft.a
LIBFT = libft.a

SRC = src/ft_flags.utils.c \
      src/ft_freeall.c \
      src/ft_printf.c \
      src/ft_printptr_hex.c \
      src/ft_printupper_hex.c \
      src/ft_fmtinit.c \
      src/ft_padandprint.c \
      src/ft_printlower_hex.c \
      src/ft_printstr.c \
      src/ft_utoabase.c \
      src/ft_format.utils.c \
      src/ft_printchar.c \
      src/ft_printnbr.c \
      src/ft_zero.c \
      src/ft_printunsigned.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTDIR)
	cp $(LIBFTPATH) ./
	mv $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)

bonus : $(NAME)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all
