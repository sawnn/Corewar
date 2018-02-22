/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** a
*/

#ifndef MY_H
#define MY_H
#define READ_SIZE (1)
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "op.h"

typedef	struct	s_op {
	char	**arg;
	int	*ac;
	char	**tab;
} t_op;

/*UTILITY.C*/
int	my_strcmp(char *, char *);
int	length_tab(char **);
char	*my_strdup(char *);
char	*my_strcpy(char *, char *);
int	my_isnum(char *);

/*PARSEUR.C*/
char	**parseur(char *, char *, int, char *);

/*INIT_OP.C*/
int	init_op(t_op *);
int	init_ac(t_op *);
int	init_arg(t_op *);
char	**check_header(int fd, char **save, int check);

/*ERROR.C*/
int	check_name(t_op, char **);
int	check_ac(t_op, char **, int);
int	check_error(t_op, char **);
int	check_param(char *);
int	check_arg(t_op, int, char, char *);

/*MY_STR_TO_WORD_ARRAY.C*/
char	**my_str_to_word_array(char *str);

/*GET_NEXT_LINE.C*/
char	*get_next_line(int fd);
char	*my_strcat(char *, char *);
int	my_strlen(char *);
char    *my_strncat(char *dest, char *src, int nb);

/*MY_PUTNBR_BASE.C*/
int	my_getnbr(char *str);
char    *my_putnbr_base(unsigned int nbr, char *base);

/*ASSEMBLEUR.C*/
int	assembleur(char *, char **);
header_t init_header(char **);
/*UTILITY_ASSEM.C*/
char	*take_header_str(char *);
int	my_strlenchar(char *, char);
void	*my_memset(char *, int, size_t);

/*FILE.C*/
char	*find_file_name(char *);
#endif
