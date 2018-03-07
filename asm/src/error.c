/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** ok
*/

#include "../include/my.h"

int	is_label(char *label)
{
	int i = -1;
	int j = -1;
	int check = 0;

	while (label[++i] != '\0') {
		while (LABEL_CHARS[++j] != label[i] && LABEL_CHARS[j] != '\0');
		if (LABEL_CHARS[j] != label[i])
			return (84);
		j = -1;
	}
	return (0);
}

int	check_name(t_op *ope, char **instruct, int bool, int i)
{
	static int o = 2;
	static int j = -1;

	ope->label = j == -1 ? malloc(sizeof(char*) * o) : ope->label;
	if (instruct[0][my_strlen(instruct[0]) - 1] == LABEL_CHAR) {
		ope->label = realloc(ope->label, sizeof(char *) * o++);
		ope->label[++j] = malloc(sizeof(char) * my_strlen(instruct[0]));
		if (ope->label[j] == NULL)
			return (84);
		ope->label[j][0] = '\0';
		ope->label[j] = my_strdup(instruct[0]);
		ope->label[j][my_strlen(instruct[0]) - 1] = '\0';
		if (is_label(ope->label[j]) == 84)
			return (84);
		ope->label[j + 1] = NULL;		
		bool = 1;
		if (instruct[1] == NULL)
			return (-1);
	}
//	ope->label[j + 1] = NULL;
	while (ope->tab[++i] != NULL) {
		if (my_strcmp(instruct[bool], ope->tab[i]) == 0)
			return (i);
	}
	return (84);
}


int	put_label(t_op *ope, char *param, int nbr, int o)
{
	static int i = 2;
	static int j = -1;

//	if (is_label(&param[nbr]) == 84)
//		return (84);
	if (j == -1)
		ope->check_lab = malloc(sizeof(char*) * i++);
	else
		ope->check_lab = realloc(ope->check_lab, sizeof(char*) * i++);
	ope->check_lab[++j] = malloc(sizeof(char) * my_strlen(param));
	if (ope->check_lab[j] == NULL)
		return (84);
	while (param[++o] != '\0')
		ope->check_lab[j][o - nbr] = param[o];
	ope->check_lab[j][o - nbr] = '\0';
	ope->check_lab[j + 1] = NULL;
	ope->isempty = 1;
	return (1);
}

int	check_param(char *param, t_op *ope)
{
	int nbr;

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
			return (check_param(param, ope));
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
	int o = 0;

	if (instruct[0][my_strlen(instruct[0]) - 1] == LABEL_CHAR)
		i--;
	if (i != ope->ac[j] + 1)
		return (84);
	while (instruct[++k]) {
		if (instruct[k][o] == '%')
			check = check_arg(ope, j, 'D', instruct[k]);
		else if (instruct[k][o] == 'r')
			check = check_arg(ope, j, 'R', instruct[k]);
		else
			check = check_arg(ope, j, 'I', instruct[k]);
		if (check == 84)
			return (84);
		o = 0;
	}
	return (0);
}

int	check_error(t_op *ope, char **instruct)
{
	int i = -1;
	int j = 0;
	int k = 0;

	if ((i = check_name(ope, instruct, 0, -1)) == 84)
		return (84);
	if (i == -1)
		return (i);
	if (instruct[0][my_strlen(instruct[0]) - 1] == LABEL_CHAR)
		k = 1;
	if ((i = check_ac(ope, instruct, i, k)) == 84)
		return (84);
	return (i);
}
