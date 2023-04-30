

NAME = cub3D
FRAEMWORKS = -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

SRC = gnl/get_next_line.c \
    gnl/get_next_line_utils.c \
    main.c \
    src/utils/utils.c \
    src/map/height.c \
    src/map/get_map.c \
    src/map/fill_map.c \
    src/check/check.c \
    src/check/wall_check.c \
    src/check/character_check.c \
    src/check/value_check.c \
    src/game/game.c \
    src/game/draw.c \
    src/game/ray_casting.c \
    src/game/control.c \
    src/game/move.c \

INCLUDES = libft/libft.a mlx/libmlx.a

OBJ=$(SRC:.c=.o)
.c.o:
	@gcc $(FLAGS) -c $< -o $@

all: $(OBJ)
	@make -C ./libft
	@make -C ./mlx
	@gcc $(OBJ) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)


clean:
	@rm -rf $(OBJ)
	@make clean -C ./libft
	@make clean -C ./mlx

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
