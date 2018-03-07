/*
** EPITECH PROJECT, 2018
** check exception
** File description:
** gaspacho andalou
*/

#include "my.h"

char	*check_exception(char *str, int opcode)
{
	int	i = -1;

	if (opcode != 10 && opcode != 11
		&& opcode != 14)
		return (str);
	while (str[++i] != '\0')
		str[i] == '4' ? str[i] = '2' : 0;
	str[i] = '\0';
	return (str);
}
