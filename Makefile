##
## EPITECH PROJECT, 2016
## wireframe
## File description:
## wireframe's makefile
##

CFLAGS	=	-Iinclude

SRC	=	src/infog.c			\
		src/match.c			\
		src/my_draw_line.c		\
		src/my_put_pixel.c		\
		src/get_coordinates.c		\
		src/window.c			\
		src/my_utils.c			\
		src/my_parallel_projection.c	\
		src/my_isometric_projection.c	\
		src/my_getnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	wireframe

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lc_graph_prog -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
