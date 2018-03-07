/*
** EPITECH PROJECT, 2018
** cycle
** File description:
** gaspacho andalou
*/

#include "my.h"

int	cycle(int i)
{
	static int	cycle = 0;

	if (i != -1)
		cycle += 1;
	return (cycle);
}
