NAME = fractol

SRC = main.c fractol_tools.c

MLX =-Lmlx -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRC:.c=.o)

CC = cc

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
		${CC} -Wall -Werror -Wextra ${OBJ} $(MLX) -o fractol
clean:
	rm -rf ${OBJ}
	
fclean:clean
	rm -rf ${NAME}
	
re: fclean all