SOURCES = calculate.c ft_substr.c move_a_to_b.c reverse_rotate.c turk_algorithm.c check_fuctions.c indexing.c push.c rotate.c turk_algorithm_tool.c ft_atoi.c main.c push_swap.c stack_tool.c utils.c ft_split.c swap.c set_target.c
CFLAGS += -Wall -Wextra -Werror
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re