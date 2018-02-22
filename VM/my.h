/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** a
*/

#ifndef MY_H
#define MY_H
#define READ_SIZE (100)
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef	struct	s_op {
	char	*name;
	int	ac;
	char	**tab;
} t_op;

int virtual_machine(char *file);
/*UTILITY.C*/
int	my_strcmp(char *, char *);
int	length_tab(char **);
char	*my_strdup(char *);
char	*my_strcpy(char *, char *);
int	my_isnum(char *);


/*MY_STR_TO_WORD_ARRAY.C*/
char	**my_str_to_word_array(char *str);

/*GET_NEXT_LINE.C*/
char	*get_next_line(int fd);
int	my_strlen(char *);

#endif
