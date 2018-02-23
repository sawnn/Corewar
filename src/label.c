/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my.h"

int	find_label(char *str)
{
	int	i = my_strlen(str);

	if (str[i - 1] == LABEL_CHAR)
		return (1);
	return (0);
}
