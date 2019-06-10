##
## EPITECH PROJECT, 2019
## MUL_bootstrap_my_world
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -rf

SRC	=	project_iso_point.c \
		main.c 	\
		vertx_drawer.c		\
		test_volume.c

CFLAGS	=	-I./include

LIB	=	-l csfml-graphics -l csfml-window -lm

OBJ	=	$(SRC:.c=.o)

NAME	=	my_world

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

mr_clean :
	find -type f -name "*~" -delete -o -type f -name "#*#" -delete

.PHONY : all clean fclean mr_clean re
