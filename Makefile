##
## Makefile for infog in /home/tsuna/Epitech/projects/Infograph
## 
## Made by Martin Van Elslande
## Login   <martin.van-elslande@epitech.eu>
## 
## Started on  Thu Nov 10 15:13:37 2016 Martin Van Elslande
## Last update Wed Dec  7 22:55:02 2016 Martin Van Elslande
##

CFLAGS	=	-I include

SRC	=	infog.c			\
		src/my_draw_line.c		\
		src/my_put_pixel.c	\
		get_coordinates.c	\
		src/window.c		\
		src/my_utils.c		\
		src/my_parallel_projection.c \
		my_getnbr.c

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
