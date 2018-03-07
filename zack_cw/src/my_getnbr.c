/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** gaspacho andalou
*/

#include "my.h"

int	my_getnbr(char *str)
{
	int	i = -1;
	int	nb = 0;
	int	nb_total = 0;

	while (str[++i] != '\0') {
		if (str[i] >= 48 && str[i] <= 57)
			nb = str[i] - 48;
		else
			return (85);
		nb_total = nb_total * 10 + nb;
	}
	if (str[0] == '-')
		nb_total = nb_total * (-1);
	return (nb_total);
}
