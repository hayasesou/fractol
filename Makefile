NAME = fractol
CFLAGS = -Wall -Wextra -Werror -O2 -fsanitize=address -g
FILES = main.c image.c deal.c\
		mandel_deal_mlx.c mandel.c\
		julia.c julia_deal_mlx.c
OBJECTS = $(FILES:.c=.o)
LIBFT_DIR = ./libft
LIBFT = ft
MLX_DIR = ./mlx
MLX = mlx
INCLUDE_DIR = ./include
PRINTF_DIR = ./printf
PRINTF = ftprintf
INCLUDE = -I $(LIBFT_DIR)  -I $(MLX_DIR) -I $(INCLUDE_DIR) -I$(PRINTF_DIR)

all:$(NAME)

$(NAME): $(OBJECTS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -L$(LIBFT_DIR) -l$(LIBFT) -L$(MLX_DIR) -l$(MLX) \
	-L$(PRINTF_DIR) -l$(PRINTF) -framework OpenGL -framework AppKit $(OBJECTS) -o $(NAME)

.c.o: $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	make -C $(PRINTF_DIR) clean
	$(RM) $(OBJECTS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re: fclean all