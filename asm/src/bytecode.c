/*
** EPITECH PROJECT, 2018
** bytecode.c
** File description:
** a
*/

#include "../include/my.h"

int	bin_to_dec(char *bin)
{
	int total = 0;
	int nb = 128;
	int o = 0;

	while (o < 8) {
		total = total + (nb * (bin[o] - 48));
		o++;
		nb /= 2;
	}
	return (total);
}

int	get_bytecode(char **arg, int fd)
{
	int  i = -1;
	int o = 0;
	int byte = 0;
	char bytcode[8];

	while (arg[++i] != NULL) {
		if (arg[i][0] == 'r') {
			bytcode[o++] = '0';
			bytcode[o++] = '1';
		}
		else if (arg[i][0] == '%') {
			bytcode[o++] = '1';
			bytcode[o++] = '0';
		}
		else {
			bytcode[o++] = '1';
			bytcode[o++] = '1';
		}
	}
	while (o != 8 && (bytcode[o++] = '0'));
	bytcode[o] = '\0';
	byte = bin_to_dec(bytcode);
	write(fd, &byte, 1);

}

int	is_bytecode(char *str)
{
	char    *sp[5] = {"live", "fork", "lfork", "zjmp", NULL};
	int     i = -1;

	while (++i != length_tab(sp)) {
		if (my_strcmp(sp[i], str) == 0)
			return (1);
	}
	return (0);
}
