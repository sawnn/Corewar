/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** a
*/

#include "my.h"

int main(int ac, char **av)
{
	if (ac != 2 || av[1][0] == '\0')
		return (84);
	if (virtual_machine(av[1]) == 84)
		return (84);
	return (0);
}
