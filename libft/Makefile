SRC = 	./ft_strlen.c \
		./ft_putstr_fd.c \
		./ft_putnbr_fd.c \
		./ft_putchar_fd.c
CFLAGS += -Wall -Werror -Wextra
NAME = libft.a
OBJ = $(SRC:.c=.o)
.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -c $(SRC)
	ar -rc $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
