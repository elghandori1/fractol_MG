
NAME = fractol

SRC = mandelbrot.c generetor.c events.c main.c tools.c parcing.c julia.c

MLX =  -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

CFLAGS = -Wall -Werror -Wextra

CC = cc

HEADER = fractol.h

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${SRC} ${HEADER}
		${CC} ${SRC} ${CFLAGS} -o ${NAME} $(MLX)

clean:
	rm -rf ${NAME}
	
fclean:
	rm -rf ${NAME} 

all: ${NAME}

re: fclean all
