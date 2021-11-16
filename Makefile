NAME	= 	fdf

FLAGS	= 	-Wall -Werror -Wextra -g -fsanitize=address

SRC		= 	src/err_in_map.c \
			src/init_map.c \
			src/err_print.c \
			src/events.c \
			src/screen.c \
			src/draw_net.c \
            fdf.c 

OBJ		= 	$(SRC:.c=.o)

OBJ_DIR	= 	./obj

INC		= -I ./include -I ./libft -I ./mlx

LIBFT	=	-L ./libft -lft

MLX		=	-L ./mlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

lft:
	make -C ./libft
	make -C ./mlx

$(NAME): lft $(OBJ)
	gcc $(FLAGS) $(INC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

clean:
	/bin/rm -rf $(OBJ)
	make -C ./libft/ clean
	make -C ./mlx/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft/ fclean

re: fclean all