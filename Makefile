NAME = fractol
CFLAGS = -Wall -Wextra -Werror -O2 -fsanitize=address
MFILES = main.c image.c deal.c mandel_deal_mlx.c mandel.c julia.c julia_deal_mlx.c
BFILES = main.c image.c deal_bonus.c mandel_deal_mlx.c mandel.c julia.c julia_deal_mlx.c
LIBFT_DIR = ./libft
LIBFT = ft
MLX_DIR = ./minilibx-linux
MLX = mlx
INCLUDE_DIR = ./include
PRINTF_DIR = ./printf
PRINTF = ftprintf
INCLUDE = -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(INCLUDE_DIR) -I$(PRINTF_DIR)
LDFLAGS = -L$(LIBFT_DIR) -l$(LIBFT) -L$(MLX_DIR) -l$(MLX) \
	-L$(PRINTF_DIR) -l$(PRINTF) -lX11 -lXext -lm

TAR = minilibx-linux.tgz

ifdef is_bonus
	SRCS = $(BFILES)
else
	SRCS = $(MFILES)
endif

OBJECTS = $(SRCS:.c=.o)

all: extract_mlx $(NAME)

extract_mlx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		tar -xvf $(TAR); \
	fi

$(NAME): $(OBJECTS) $(LIBFT_DIR)/lib$(LIBFT).a $(MLX_DIR)/lib$(MLX).a $(PRINTF_DIR)/lib$(PRINTF).a
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $@

$(LIBFT_DIR)/lib$(LIBFT).a:
	make -C $(LIBFT_DIR)

$(MLX_DIR)/lib$(MLX).a: extract_mlx
	make -C $(MLX_DIR)

$(PRINTF_DIR)/lib$(PRINTF).a:
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus:
	$(MAKE) is_bonus=1

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

.PHONY: all bonus clean fclean re extract_mlx