

NAME = cub3D
FRAEMWORKS = -framework OpenGL -framework AppKit -g
FLAGS = -Wall -Wextra -Werror

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
    src/draw/draw.c \

INCLUDES = libft/libft.a mlx/libmlx.a

OBJ=$(SRC:.c=.o)

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
