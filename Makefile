CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
RM = rm -f
LIB_SRC = ft_putchar.c ft_putnbr.c ft_putstr.c print_hexadecimal.c \
ft_printf.c


LIB_OBJ = $(LIB_SRC:.c=.o)

all: $(NAME)
$(NAME): $(LIB_OBJ)
	ar -rc $(NAME) $(LIB_OBJ)


%.o: %.c ft_printf.h
	$(CC) ${CFLAGS} -c $< -o $@

clean :
	$(RM) $(LIB_OBJ)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY: all clean fclean re