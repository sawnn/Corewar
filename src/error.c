/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** ok
*/

#include "../include/my.h"

int	check_name(t_op ope, char **instruct)
{
	int	i = -1;

	while (ope.tab[++i] != NULL) {
		if (my_strcmp(instruct[0], ope.tab[i]) == 0)
			return (i);
	}
	return (84);
}

int	check_param(char *param)
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
		param[0] = '0';
		if (my_isnum(param) == 84)
			return (84);
	}
	else if (my_isnum(param) == 84)
		return (84);
	return (1);
}

int	check_arg(t_op ope, int j, char arg, char *param)
{
	static int i = -1;
	int nb = my_strlen(ope.arg[j]);

	if (ope.arg[j][i + 1] == 'O')
		i = i + 2;
	while (ope.arg[j][++i] != '\0') {
		if (ope.arg[j][i] == arg) {
			i = i == nb - 1 ? -1 : i;
			return (check_param(param));
		}
		if (ope.arg[j][i + 1] != 'O')
			return (84);
	}
}

int	check_ac(t_op ope, char **instruct, int j)
{
	int i = length_tab(instruct);
	int check;
	int k = 0;
	int o = 0;

	if (i != ope.ac[j] + 1)
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

int	check_error(t_op ope, char **instruct)
{
	int i = -1;
	int j = 0;

	if ((i = check_name(ope, instruct)) == 84)
		return (84);
	if ((i = check_ac(ope, instruct, i)) == 84)
		return (84);
	return (i);
}
