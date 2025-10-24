SRC = ./ft_printf.c
CFLAGS += -Wall -Werror -Wextra
NAME = libftprintf.a
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SRC) libft.a
	$(CC) -c $(SRC)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

libft.a :
	cd libft
	make fclean | make | make clean