##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a
##

SRC	=	src/main.c			\
		src/utility.c			\
		src/get_next_line.c		\
		src/my_str_to_word_array.c	\
		src/parseur.c			\
		src/my_putnbr_base.c		\
		src/init_op.c			\
		src/error.c			\
		src/utility_assem.c		\
		src/assembleur.c		\
		src/file.c

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

all:	$(NAME)

CFLAGS	= -g3
$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

