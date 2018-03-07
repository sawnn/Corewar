/*
** EPITECH PROJECT, 2018
** init tab
** File description:
** gaspacho andalou
*/

#include "my.h"
#include "op.h"

char	**init_tab_op(char **tab)
{
	int	i = -1;

	if ((tab = malloc(sizeof(char *) * 16 + sizeof(char *))) == NULL)
		return (NULL);
	while (++i <= 15) {
		if ((tab[i] = malloc(sizeof(char) * 4)) == NULL)
			return (NULL);
		tab[i][0] = (i + 1) + 48;
	}
	tab[i] = NULL;
	return (tab);
}

char	**init_tab_arg(char **tab)
{
        tab[0][1] = '1';
	tab[1][1] = '2';
	tab[2][1] = '2';
	tab[3][1] = '3';
	tab[4][1] = '3';
	tab[5][1] = '3';
	tab[6][1] = '3';
	tab[7][1] = '3';
	tab[8][1] = '1';
	tab[9][1] = '3';
	tab[10][1] = '3';
	tab[11][1] = '1';
	tab[12][1] = '2';
	tab[13][1] = '3';
	tab[14][1] = '1';
	tab[15][1] = '1';
	return (tab);
}
