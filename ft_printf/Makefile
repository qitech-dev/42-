SOURCES = ft_printf.c ft_putnbr_len_fd.c ft_strlen.c ft_putchar_len_fd.c ft_putnbr_u_len.c ft_putendl_len_fd.c ft_putptr_len.c ft_putnbr_base_len.c ft_putstr_len_fd.c
CFLAGS += -Wall -Wextra -Werror
NAME = libftprintf.a
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re