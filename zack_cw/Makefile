##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a
##

SRC	=	./src/main.c			\
		./src/op.c			\
		./src/my_getnbr.c		\
		./src/utility.c			\
		./src/utility2.c		\
		./src/init_tab.c		\
		./src/get_reads.c		\
		./src/read.c			\
		./src/pc.c			\
		./src/cycle.c			\
		./src/handle_error.c		\
		./src/check_exceptions.c

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

all:	$(NAME)

CFLAGS	= -I  include -g3

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

