/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my.h"

void	is_remove_bytecode(char *str, int *octect)
{
	char	*sp[5] = {"live", "fork", "lfork", "zjmp", NULL};
	int	i = -1;

	while (++i != length_tab(sp)) {
		if (my_strcmp(sp[i], str) == 0)
			(*octect) -= 1;
	}
}
