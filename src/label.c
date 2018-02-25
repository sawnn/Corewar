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
	if (str[0] == DIRECT_CHAR && str[1] != LABEL_CHAR)
		return (2);
	if (str[0] >= '0' && str[0] <= '9' || str[1] == LABEL_CHAR)
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

int	find_octect_line(char **tab, int pos)
{
	int	octect = 0;
	int	i = pos;
	static	int	j = 0;

	if (tab[i] == NULL)
		return (0);
	octect += 2; // pour op code et bytecodes
	//si ya que le label return 0
//printf("length tab = %d\n", length_tab(tab));
	while (i != length_tab(tab)) {
		//		printf("%d: tab[%d] = %s\n", j, i, tab[i]);
		which_arg_is(tab[i]) == 1 ? octect += REG_SIZE : 0;
		which_arg_is(tab[i]) == 2 ? octect += DIR_SIZE : 0;
		which_arg_is(tab[i]) == 3 ? octect += IND_SIZE : 0;
		i++;
	}
	j += 1;
	return (octect);
}
