/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** a
*/

#include "../include/my.h"

int	my_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0') {
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	length_tab(char **tab)
{
	int	i = -1;

	while (tab[++i] != NULL);
	return (i);
}

char	*my_strdup(char *src)
{
	char	*d;
	int	taille = my_strlen(src) + 1;

	d = malloc(sizeof(char) * taille);
	if (d == NULL)
		return (NULL);
	my_strcpy(d, src);
	return (d);
}

char	*my_strcpy(char *dest, char *src)
{
	int	i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int     my_isnum(char *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;
	while (str[i]) {
		if ((str[i] < '0' || str[i] > '9'))
			return (84);
		i = i + 1;
	}
	if (str[0] == '\0')
		return (84);
	return (0);
}
