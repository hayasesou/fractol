NAME = fractol
CFALGS = -Wall Wextra Werror
FILES = test.c
OBJECTS = $(FILES:.c=.o)
LIBFT_DIR = ./libft
LIBFT = ft
MLX_DIR = ./mlx
MLX = mlx

all:$(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(LIBFT) -L$(MLX_DIR) -l$(MLX) -framework OpenGL -framework AppKit $(OBJECTS) -o $(NAME)

.c.o: $(OBJECTS)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR)  -I $(MLX_DIR) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJECTS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all