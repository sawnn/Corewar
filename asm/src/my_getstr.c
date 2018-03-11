/*
** EPITECH PROJECT, 2018
** getstr
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

int	my_nblen(int nb)
{
	int	x = 1;
	int	i = 0;

	if (nb < 0)
		nb = nb * -1;
	while ((nb / x) >= 10) {
		x = x * 10;
	}
	while (x != 0) {
		i++;
		x = x / 10;
	}
	return (i);
}

char	*my_getstr(int nb)
{
	int	x = 1;
	int	i = 0;
	char	*tmp = NULL;

	if ((tmp = malloc(sizeof(char) * (my_nblen(nb) + 3))) == NULL)
		return (NULL);
	tmp[i] = '%';
	if (nb < 0) {
		nb = nb * (-1);
		tmp[1] = '-';
		i += 1;
	}
	while ((nb / x) >= 10)
		x *= 10;
	while (x != 0) {
		tmp[++i] = (((nb / x) % 10 + 48));
		x /= 10;
	}
	tmp[i + 1] = '\0';
	return (tmp);
}
