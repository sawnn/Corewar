/*
** EPITECH PROJECT, 2018
** utility 3
** File description:
** gaspacho andalou
*/

#include "my.h"

int	my_strlen(char *str)
{
	int	i = -1;

	while (str[++i] != '\0');
	return (i);
}

char	*my_strndup(char *str, int n)
{
	int	i = -1;
	char	*tmp = NULL;

	if ((tmp = malloc(sizeof(char) * my_strlen(str) + 5)) == NULL)
		return (NULL);
	while (++i != n)
		tmp[i] = str[i];
	tmp[i] = '\0';
	return (tmp);
}

int	my_nblen(int nb)
{
	int	x = 1;
	int	i = 0;

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
	int	i = -1;
	char	*tmp = NULL;

	if ((tmp = malloc(sizeof(char) * (my_nblen(nb) + 1))) == NULL)
		return (NULL);
	if (nb < 0) {
		nb = nb * (-1);
		tmp[0] = '-';
		i += 1;
	}
	while ((nb / x) >= 10)
		x *= 10;
	while (x != 0) {
		tmp[++i] = (((nb / x) % 10 + 48));
		x /= 10;
	}
	return (tmp);
}

char	*getbin(int nb)
{
	int	x = 1;
	int	i = 0;
	char	*tmp = NULL;

	if ((tmp = malloc(sizeof(char) * my_nblen(nb) + 7)) == NULL)
		return (NULL);
	while ((nb / x) >= 2)
		x = x * 2;
	while (x > 0) {
		tmp[i] = ((nb / x) % 2 + 48);
		i += 1;
		x = x / 2;
	}
	tmp[i] = '\0';
	return (tmp);
}
