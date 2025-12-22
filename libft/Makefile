NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =  ft_atoi.c \
			 ft_atol.c	\
       ft_isalnum.c \
       ft_islower.c \
       ft_itoa.c \
       ft_memccpy.c \
       ft_mempcpy.c \
       ft_putnbr.c \
       ft_strcat.c \
       ft_striteri.c \
       ft_strmapi.c \
       ft_strrchr.c \
       ft_toupper.c \
       ft_bzero.c \
       ft_isalpha.c \
       ft_isprint.c \
       ft_memchr.c \
       ft_memrchr.c \
       ft_putnbr_fd.c \
       ft_strchr.c \
       ft_strjoin.c \
       ft_strncat.c \
       ft_strstr.c \
       ft_calloc.c \
       ft_isascii.c \
       ft_isset.c \
       ft_memcmp.c \
       ft_memset.c \
       ft_putstr.c \
       ft_strcmp.c \
       ft_strlcat.c \
       ft_strncmp.c \
       ft_strtrim.c \
       ft_countword.c \
       ft_ischarset.c \
       ft_isspace.c \
       ft_memcpy.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_strcpy.c \
       ft_strlcpy.c \
       ft_strncpy.c \
       ft_substr.c \
       ft_freeiter.c \
       ft_isdigit.c \
       ft_isupper.c \
       ft_memmove.c \
       ft_putendl_fd.c \
       ft_split.c \
       ft_strdup.c \
       ft_strlen.c \
       ft_strnstr.c \
       ft_tolower.c

OBJ = $(SRC:.c=.o)

SRCBO = ft_lstadd_back.c \
        ft_lstadd_front.c \
        ft_lstclear.c \
        ft_lstdelone.c \
        ft_lstiter.c \
        ft_lstlast.c \
        ft_lstmap.c \
        ft_lstnew.c \
        ft_lstsize.c

OBJBO = $(SRCBO:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJBO)
	ar -rcs $(NAME) $(OBJ) $(OBJBO)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJBO) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
