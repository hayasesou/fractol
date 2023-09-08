NAME = fractol
CFLAGS = -Wall -Wextra -Werror -O2
MFILES = main.c image.c deal.c\
		mandel_deal_mlx.c mandel.c\
		julia.c julia_deal_mlx.c
BFILES = main.c image.c deal_bonus.c\
		mandel_deal_mlx.c mandel.c\
		julia.c julia_deal_mlx.c
LIBFT_DIR = ./libft
LIBFT = ft
MLX_DIR = ./mlx
MLX = mlx
INCLUDE_DIR = ./include
PRINTF_DIR = ./printf
PRINTF = ftprintf
INCLUDE = -I $(LIBFT_DIR)  -I $(MLX_DIR) -I $(INCLUDE_DIR) -I$(PRINTF_DIR)
LDFALGS = -L$(LIBFT_DIR) -l$(LIBFT) -L$(MLX_DIR) -l$(MLX) \
	-L$(PRINTF_DIR) -l$(PRINTF)

ifdef is_bonus
	OBJECTS = $(BFILES:.c=.o)
else
	OBJECTS = $(MFILES:.c=.o)
endif

all:$(NAME)

$(NAME): $(OBJECTS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(LDFALGS) -framework OpenGL -framework AppKit $(OBJECTS) -o $@

bonus:
	make is_bonus=1

.c.o: $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	make -C $(PRINTF_DIR) clean
	$(RM) $(BFILES:.c=.o) $(MFILES:.c=.o)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re: fclean all