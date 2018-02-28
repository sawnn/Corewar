##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a
##

SRC	=	asm/src/main.c			\
		asm/src/utility.c		\
		asm/src/get_next_line.c		\
		asm/src/my_str_to_word_array.c	\
		asm/src/parseur.c		\
		asm/src/my_putnbr_base.c	\
		asm/src/init_op.c		\
		asm/src/error.c			\
		asm/src/utility_assem.c		\
		asm/src/assembleur.c		\
		asm/src/file.c			\
		asm/src/label.c			\
		asm/src/list.c			\
		asm/src/basic.c			\
		asm/src/label_bis.c		\
		asm/src/write_op.c		\
		asm/src/my_getstr.c		\
		asm/src/convert_endian.c

OBJ	=	$(SRC:.c=.o)

NAME	=	asm/asm

all:	$(NAME)

CFLAGS	= -I  include -g3

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ./*.cor

re:	fclean all

