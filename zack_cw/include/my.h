/*
** EPITECH PROJECT, 2018
** my
** File description:
** gaspacho andalou
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include "op.h"

typedef struct s_champ {
	header_t	header;
	int		fd;
	char		*file;
	char		*name;
	int		prog_size;
	char		*comment;
	int		number;
	int		carry;
	int		pc;
	int		live;
	int		cycle_wait;
	int		*reg;
	struct s_champ	*next;
}t_champ;

typedef struct s_pc {
	int		pc;
	int		prog_nbr;
	struct s_pc	*list_pc;
	struct s_pc	*next;
}t_pc;

/*MAIN.C*/
t_champ *fill_champion(t_champ *, int, char *);
int     init_game(int, char **, char *);
int     main(int, char **);

/*UTILITY.C*/
int	my_strlen(char *);
char	*my_strndup(char *, int);
int	my_getnbr(char *);
char	*my_getstr(int);
char	*getbin(int);

/*UTILITY2.C*/
char	*my_strcat(char *, char *);
char	*my_memset(char *, char, int);
int	my_strcmp(char *, char *);
char	*my_strdup(char *);

/*INIT.C*/
char	**init_tab_arg(char **);
char	**init_tab_op(char **);
int	*init_reg(t_champ *);

/*GET_READS.C*/
int     find_op(int, char **);
char    find_byte(char *);
char    *get_bytes(int, char);
char	*get_reads(int, int);
char	*get_params(int, int, int *);

/*READ.C*/
int	*my_read(char *, int, int *);
int	read_inst(t_champ *, char *, int i);
char	*put_int_char(int *, char *, int *);

/*PC.C*/
int	set_pc(t_champ *, t_pc *, int);
t_pc	*new_pc(t_pc *, int, int);

/*CYCLE.C*/
int	cycle(int);

/*HANDLE_ERROR.C*/
int	check_ext(char *);
int	handle_error(int, char **);

/*CHECK_EXCEPTIONS.C*/
char    *check_exception(char *, int);
