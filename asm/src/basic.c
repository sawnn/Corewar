/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my.h"

void	my_putstr(char *str, int fd)
{
	write(fd, str, my_strlen(str));
}

void	print_tab(char **tab)
{
	int	i = -1;

	while (tab[++i] != NULL)
		my_putstr(tab[i], 1);
}

int	my_strlenchar(char *str, char c)
{
	int	i = -1;

	while (str[++i] != c && str[i] != '\0');
	return (i);
}

int	strlen_slash(char *str)
{
	int i = -1;
	int check = -1;
	while (str[++i] != '\0')
		if (str[i] == '/')
			check = i;
	return (check);
}
