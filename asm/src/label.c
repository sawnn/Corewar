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
	if (str[0] == '-' || (str[0] >= '0' && str[0] <= '9') || str[0] == LABEL_CHAR)
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
		//printf("tab[%d][0] = %c - tab[%d][1] = %c\n", i, tab[i][0], i, tab[i][1]);
		if ((tab[i][0] == DIRECT_CHAR) && (tab[i][1] == LABEL_CHAR)) {
			return (1);
		}
		else if (tab[i][0] == LABEL_CHAR)
			return (1);
	}
	return (0);
}

int	find_octect_line(char **tab, int pos, int **olabel)
{
	int	octect = 0;
	int	i = pos + 1;
	
	if (tab[1] == NULL) //ou remettre i ?
		return (0);
	octect += 2;
	is_remove_bytecode(tab[pos], &octect);
	while (i != length_tab(tab)) {
		if (is_special_case(tab[pos]) == 1)
			which_arg_is_special(tab[i], &octect);
		else {
			which_arg_is(tab[i]) == 1 ? octect += REG_SIZE : 0;
			which_arg_is(tab[i]) == 2 ? octect += DIR_SIZE : 0;
			which_arg_is(tab[i]) == 3 ? octect += IND_SIZE : 0;
		}
		i++;
	}
	return (octect);
}

