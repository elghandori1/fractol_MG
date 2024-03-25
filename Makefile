
NAME = fractol

NAME_BONUS = fractol_bonus

SRC = mandelbrot.c events.c main.c tools.c tools2.c parcing.c julia.c

MLX =  -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

CFLAGS = -Wall -Werror -Wextra

CC = cc

SRC_BONUS = ./bonus/main_bonus.c ./bonus/burning_bonus.c ./bonus/events_bonus.c ./bonus/tools_bonus.c tools2.c

OBJ = $(SRC:.c=.o)
OBJSB = $(SRC_BONUS:.c=.o) 

all: $(NAME)

bonus : $(NAME_BONUS)

${NAME}: ${SRC}
		@${CC} ${SRC} ${CFLAGS} -o ${NAME} $(MLX)

${NAME_BONUS}: ${B_C}
		@${CC} ${CFLAGS} ${SRC_BONUS} ${MLX} -o ${NAME_BONUS}

clean:
	@rm -rf $(OBJ) $(OBJSB)
	
fclean:
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean all bonus
