##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a
##

SRC	=	main.c			\
		v_machine.c

OBJ	=	$(SRC:.c=.o)

NAME	=	yolotron-vm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

