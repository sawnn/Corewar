/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** a
*/

#include "../include/my.h"

int	error(int ac, char **av)
{
	int i = 0;

	if (ac != 2)
		return (84);
	i = strlen_check(av[1], '.');
	if (i == -1)
		return (84);
	if (my_strcmp(&av[1][i], ".s") != 0) {
		return (84);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char **save;
	int fd;
	char ***all;

	if (error(ac, av) == 84 || fd == -1)
		return (84);
	if ((save = parseur(av[1], av[2], 2, NULL)) == NULL)
		return (84);
	else if (save[1] == NULL)
		return (84);
	all = fill_all_tab(all, save);
	fd = open(my_strcat(find_file_name(av[1]), ".cor"), FLAGS_OPEN);
	if (all == NULL || fd == -1)
		return (84);
	assembleur(save, all, fd);
	return (0);
}
