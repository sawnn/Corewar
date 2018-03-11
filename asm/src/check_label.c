/*
** EPITECH PROJECT, 2018
** check_label
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

void	*check_lab(t_op check, int *i, int j, t_op ope)
{
	while (check.label[++(*i)] != NULL)
		if (*i != j
		    && my_strcmp(ope.label[j], check.label[*i]) == 0)
			return (NULL);
	*i = -1;
}

char	**check_label(char **save, t_op ope, int i, int j)
{
	t_op check = ope;

	if (save[1] == NULL || save[2] == NULL)
		return (save);
	while (ope.label[++j] != NULL) {
	        if (check_lab(check, &i, j, ope) == NULL)
			return (NULL);
	}
	j = -1;
	while (ope.isempty == 1 && ope.check_lab[++i] != NULL) {
		while (ope.label[++j] != NULL
		&& my_strcmp(ope.label[j], ope.check_lab[i]) != 0);
		if (ope.label[j] == NULL)
			return (NULL);
		j = -1;
	}
	return (save);
}
