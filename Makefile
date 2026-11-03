# Variables
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I include -I mlx
MLX = mlx/libmlx.a
SRCS = ft_split.c game_utils.c map2matrix.c valid.c valid_solution.c valid_utils.c valid_utils2.c game_keys.c game_utils2.c ft_printf.c ft_put.c main.c clean.c
OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(MLX) -lm -lX11 -lXext

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX):
	$(MAKE) -C mlx

clean:
	$(MAKE) -C mlx clean
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
