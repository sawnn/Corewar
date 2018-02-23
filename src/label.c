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
	if (str[0] >= '0' && str[0] <= '9')
		return (2);
	if (str[0] == '%')
		return (3);
	return (0);
}

int	find_label(char *str)
{
	int	i = my_strlen(str);

	if (str[i - 1] == LABEL_CHAR)
		return (1);
	return (0);
}

int	find_octect_line(char *str, int fd, char **tab)
{
	int	octect = 0;
	int	i = 2;

	octect += 2; // pour op code et bytecodes
	while (i != length_tab(tab)) {
		which_arg_is(tab[i]) == 1 ? octect += REG_SIZE : 0;
		which_arg_is(tab[i]) == 2 ? octect += DIR_SIZE : 0;
		which_arg_is(tab[i]) == 3 ? octect += IND_SIZE : 0;
		i++;
	}
	printf("octects = %d\n", octect);
	//printf("char = %c\n", c);
}
