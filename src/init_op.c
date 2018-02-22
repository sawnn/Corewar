/*
** EPITECH PROJECT, 2018
** init_op.c
** File description:
** z
*/

#include "../include/my.h"

int	init_arg(t_op *ope)
{
	ope->arg = malloc(sizeof(char *) * 16 + sizeof(char *));
	if (ope->arg == NULL)
		return (84);
	ope->arg[0] = "D";
	ope->arg[1] = "DOIR";
	ope->arg[2] = "RIOR";
	ope->arg[3] = "RRR";
	ope->arg[4] = "RRR";
	ope->arg[5] = "RODOIROIODR";
	ope->arg[6] = "ROIODROIODR";
	ope->arg[7] = "ROIODROIODR";
	ope->arg[8] = "D";
	ope->arg[9] = "RODOIDORR";
	ope->arg[10] = "RRODOIDOR";
	ope->arg[11] = "D";
	ope->arg[12] = "DOIR";
	ope->arg[13] = "RODOIDORR";
	ope->arg[14] = "D";
	ope->arg[15] = "R";
	ope->arg[16] = NULL;
}

int     init_op(t_op *ope)
{
	ope->tab = malloc(sizeof(char *) * 16 + sizeof(char *));
        if (ope->tab == NULL)
                return (84);
        ope->tab[0] = "live";
	ope->tab[1] = "ld";
        ope->tab[2] = "st";
        ope->tab[3] = "add";
        ope->tab[4] = "sub";
        ope->tab[5] = "and";
        ope->tab[6] = "or";
        ope->tab[7] = "xor";
	ope->tab[8] = "zjmp";
        ope->tab[9] = "ldi";
        ope->tab[10] = "sti";
	ope->tab[11] = "fork";
        ope->tab[12] = "lld";
        ope->tab[13] = "lldi";
        ope->tab[14] = "lfork";
        ope->tab[15] = "aff";
        ope->tab[16] = NULL;
}

int     init_ac(t_op *ope)
{
	int i = -1;

        ope->ac = malloc(sizeof(int) * 17);
	if (ope->ac == NULL)
                return (84);
        while (++i < 16) {
	        if (i + 1 == 1 || i + 1 == 9
                    || i + 1 == 12 || i + 1 == 15 || i + 1 == 16)
                        ope->ac[i] = 1;
                else if (i + 1 == 2 || i + 1 == 3 || i + 1 == 13)
                        ope->ac[i] = 2;
                else
                        ope->ac[i] = 3;
	}
        return (0);
}

int	pars_head(char **head, int i, int j)
{
	int length = length_tab(head);

	if (length != 2)
		return (84);
	j = my_strlen(head[1]);
	if (head[1][0] != '"' || head[1][j - 1] != '"')
		return (84);
	if (i == 0) {
		if (my_strcmp(".name", head[0]) != 0)
			return (84);
		else if (j - 2 > 128)
			return (84);
	}
	else {
		if (my_strcmp(".comment", head[0]) != 0)
			return (84);
		else if (j - 2 > 2048)
			return (84);
	}
	return (0);
}

char	**check_header(int fd, char **save, int check)
{
	int i = 0;
	char *str;
	char **head;

	if ((save = malloc(sizeof(char*) * 2)) == NULL)
		return (NULL);
	while (i < 2) {
		str = get_next_line(fd);
		if ((head = my_str_to_word_array(str)) == NULL)
			return (NULL);
		if (head[0] != NULL) {
			save[i] = my_strdup(str);
			check = pars_head(head, i, 0);
			save = realloc(save, sizeof(char*) * (2 + i + 1));
			i++;
		}
		if (check == 84)
			return (NULL);
	}
	return (save);
}
