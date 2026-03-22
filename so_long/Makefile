NAME = so_long
CFLAGS += -Wall -Wextra -Werror
CC = cc
MLX_DIR = ./minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC = -I. -I$(LIBFT_DIR) -I$(MLX_DIR)
SOURCES = find_p.c check_characters.c check_fuctions.c give_name.c render_map.c tools.c get_map.c init_window.c main.c give_img_ptr.c is_valid_path.c move_tools.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX_LIB):
	@make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re