NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -L./mlx -lmlx -framework AppKit -framework OpenGL 
SRCS =  main.c getnextline/get_next_line.c getnextline/get_next_line_utils.c moves.c name.check.c mapprint.c mapcheck.c floodfill.c utils.c utils2.c

OBJS= $(SRCS:.c=.o)
MINI = ./mlx/libmlx.a

all: ${NAME}

$(MINI):
	make -C ./mlx &> /dev/null

$(NAME): $(MINI) $(OBJS) 
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME) 

%.o: %.c
	${CC} -c $^ -o $@ -Wall -Werror -Wextra -g

clean:
	rm -rf ${OBJS}
	make clean -C mlx/

fclean: clean
	rm -rf ${NAME}
	make clean -C mlx/

re: fclean all
.PHONY: fclean re all clean