/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** ok
*/

#include "../include/my.h"

int	check_name(t_op *ope, char **instruct, int bool, int i)
{
	static int a = 2;
	static int j = -1;

	ope->label = j == -1 ? malloc(sizeof(char*) * a) : ope->label;
	if (instruct[0][my_strlen(instruct[0]) - 1] == LABEL_CHAR) {
		ope->label = realloc(ope->label, sizeof(char *) * a++);
		ope->label[++j] = malloc(sizeof(char) * my_strlen(instruct[0]));
		if (ope->label[j] == NULL)
			return (84);
		ope->label[j][0] = '\0';
		ope->label[j] = my_strdup(instruct[0]);
		ope->label[j][my_strlen(instruct[0]) - 1] = '\0';
		ope->label[j + 1] = NULL;
		bool = 1;
		if (instruct[1] == NULL)
			return (-1);
	}
	while (ope->tab[++i] != NULL)
		if (my_strcmp(instruct[bool], ope->tab[i]) == 0)
			return (i);
	return (84);
}


int	put_label(t_op *ope, char *param, int nbr, int a)
{
	static int i = 2;
	static int j = -1;

	if (j == -1)
		ope->check_lab = malloc(sizeof(char*) * i++);
	else
		ope->check_lab = realloc(ope->check_lab, sizeof(char*) * i++);
	ope->check_lab[++j] = malloc(sizeof(char) * my_strlen(param));
	if (ope->check_lab[j] == NULL)
		return (84);
	while (param[++a] != '\0')
		ope->check_lab[j][a - nbr] = param[a];
	ope->check_lab[j][a - nbr] = '\0';
	ope->check_lab[j + 1] = NULL;
	ope->isempty = 1;
	return (1);
}

int	check_param(char *param, t_op *ope, int nbr)
{
	if (param[0] == 'r') {
		if (my_strlen(param) > 3)
			return (84);
		param[0] = '0';
		if (my_isnum(param) == 84 ||
		(nbr = my_getnbr(param)) > 16 || nbr < 1)
			return (84);
	}
	else if (param[0] == '%') {
		if (param[1] == LABEL_CHAR)
			return (put_label(ope, param, 2, 1));
		if (my_isnum(&param[1]) == 84)
			return (84);
	}
	else if (param[0] == ':')
		return (put_label(ope, param, 1, 0));
	else if (my_isnum(param) == 84)
		return (84);
	return (1);
}

int	check_arg(t_op *ope, int j, char arg, char *param)
{
	static int cmp = 0;
	static int i = -1;
	int nb = my_strlen(ope->arg[j]);

	while (ope->arg[j][++i] != '\0') {
		if (ope->arg[j][i] == arg) {
			i = i == nb - 1 ? -1 : i;
			cmp++;
			while (ope->arg[j][i + 1] == 'O')
				i = i + 2;
			if (cmp == ope->ac[j]) {
				i = -1;
				cmp = 0;
			}
			return (check_param(param, ope, 0));
		}
		if (ope->arg[j][i + 1] != 'O')
			return (84);
		i++;
	}
}

int	check_ac(t_op *ope, char **instruct, int j, int k)
{
	int i = length_tab(instruct);
	int check;
	int a = 0;

	if (instruct[0][my_strlen(instruct[0]) - 1] == LABEL_CHAR)
		i--;
	if (i != ope->ac[j] + 1)
		return (84);
	while (instruct[++k]) {
		if (instruct[k][a] == '%')
			check = check_arg(ope, j, 'D', instruct[k]);
		else if (instruct[k][a] == 'r')
			check = check_arg(ope, j, 'R', instruct[k]);
		else
			check = check_arg(ope, j, 'I', instruct[k]);
		if (check == 84)
			return (84);
		a = 0;
	}
	return (0);
}
