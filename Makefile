SRC = ./ft_printf.c
CFLAGS += -Wall -Werror -Wextra
NAME = libftprintf.a
LIBFT_NAME = libft.a
LIBFT_DIR = libft
OBJ = $(SRC:.c=.o)
.PHONY : all clean fclean re libft.a

all : $(NAME)

$(NAME) : $(SRC) $(LIBFT_NAME)
	$(CC) -c $(SRC)
	ar -rc $(LIBFT_DIR)/$(LIBFT_NAME) $(OBJ)
	mv $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

libft.a :
	make -C $(LIBFT_DIR)