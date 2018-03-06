/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** a
*/

#include "../include/my.h"

int	help(void)
{
	write(1, "Usage:\n\t./asm file_name[.s]\n", 51);
	write(1, "DESCRIPTION\n\tfile_name\tfile in assembly language to", 51);
	write(1, " be converted into file_name.cor, an executable in", 50);
	write(1, " the Virtual Machine.", 21);
	return (0);
}

int	error(int ac, char **av)
{
	int i = 0;

	if (ac != 2)
		return (84);
	i = strlen_check(av[1], '.');
	if (i == -1)
		return (84);
	if (my_strcmp(&av[i][i], ".s") != 0) {
		return (84);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char **save;

	if (error(ac, av) == 84)
		return (84);
	if ((save = parseur(av[1], av[2], 2, NULL)) == NULL)
		return (84);
	//faudra free le tableau instruc et t_op *ope)
	if (save[1] == NULL)
		return (84);
	assembleur(av[1], save);
	return (0);
}
