/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my.h"

int	which_arg_is(char *str)
{
	if (str[0] == 'r')
		return (1);
	if (str[0] == DIRECT_CHAR)
		return (2);
	if (str[0] == '-' || (str[0] >= '0' && str[0] <= '9') || str[0] == ':')
		return (3);
	return (0);
}

int	which_arg_is_special(char *str, int *octect)
{
	if (str[0] == 'r')
		(*octect) += 1;
	else
		(*octect) += 2;
	return (1);
}

int	find_label(char *str)
{
	int	i = my_strlen(str);

	if (str[i - 1] == LABEL_CHAR)
		return (1);
	return (0);
}

int	is_special_case(char *str)
{
	char	*sp[7] = {"sti", "ldi", "lldi", "zjmp", "fork", "lfork", NULL};
	int	i = -1;

	while (++i != length_tab(sp)) {
		if (my_strcmp(sp[i], str) == 0)
			return (1);
	}
	return (0);
}

int	is_label_to_save(char **tab)
{
	int	i = -1;

	while (++i != length_tab(tab)) {
		if ((tab[i][0] == DIRECT_CHAR) && (tab[i][1] == LABEL_CHAR)) {
			return (1);
		}
		else if (tab[i][0] == LABEL_CHAR)
			return (1);
	}
	return (0);
}
