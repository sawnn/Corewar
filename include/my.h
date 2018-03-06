/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** a
*/

#ifndef MY_H
#define MY_H
#define READ_SIZE (1)
#define HELP check_error(&ope, instruc) == 84
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "op.h"
//#define	PARAM int save, int j
typedef	struct	s_op {
	char	**arg;
	int	*ac;
	char	**tab;
	char **label;
	char **check_lab;
	int isempty;
	
} t_op;

typedef	struct	s_label {
	char	*label_name;
	int	octect;
	struct	s_label *next;
} t_label;

/*UTILITY.C*/
int	my_strcmp(char *, char *);
int	length_tab(char **);
char	*my_strdup(char *);
char	*my_strcpy(char *, char *);
int	my_isnum(char *);

/*BASIC.C*/
int	my_strlenchar(char *, char);
void	my_putstr(char *, int);
void	print_tab(char **);
int	strlen_check(char *, char);

/*PARSEUR.C*/
char	**parseur(char *, char *, int, char *);
int	init_struct(t_op *);
int	send_op(t_op, char **);

/*INIT_OP.C*/
int	init_op(t_op *);
int	init_ac(t_op *);
int	init_arg(t_op *);
char	**check_header(int fd, char **save, int check);

/*ERROR.C*/
int	check_name(t_op*, char **, int, int);
int	check_ac(t_op*, char **, int, int);
int	check_error(t_op*, char **);
int	check_param(char *, t_op*);
int	check_arg(t_op*, int, char, char *);

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
void	init_header(char **, int, int);

/*UTILITY_ASSEM.C*/
char	*take_header_str(char *);
void	*my_memset(char *, char, size_t);
char	***fill_all_tab(char ***, char **);

/*FILE.C*/
char	*find_file_name(char *);

/*LABEL.C*/
int	which_arg_is(char *);
int	which_arg_is_special(char *, int *);
int	find_label(char *);
int	find_octect_line(char **, int, int **);
int	is_special_case(char *);
int	is_label_to_save(char **);
void	print_int(int *);

/*LABEL_BIS.C*/
void	is_remove_bytecode(char *, int *);

/*LIST.C*/
t_label	*add_link(t_label *, char *, int);
void	print_list(t_label *);
int	length_list(t_label *);
int	delete_t_label(t_label **, int);

/*WRITE_OP.C*/
int write_op(char ***, int, int, int);
int write_file(char ***, t_label*, int, int *);

/*MY_GETSTR*/
char	*my_getstr(int);

int	little_to_big_endian(int);
#endif
