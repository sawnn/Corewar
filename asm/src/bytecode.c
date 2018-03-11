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
	int check = 0;

	while (check < 8) {
		total = total + (nb * (bin[check] - 48));
		check++;
		nb /= 2;
	}
	return (total);
}

int	get_bytecode(char **arg, int fd)
{
	int  i = -1;
	int a = 0;
	int byte = 0;
	char bytcode[8];

	while (arg[++i] != NULL) {
		if (arg[i][0] == 'r') {
			bytcode[a++] = '0';
			bytcode[a++] = '1';
		}
		else if (arg[i][0] == '%') {
			bytcode[a++] = '1';
			bytcode[a++] = '0';
		}
		else {
			bytcode[a++] = '1';
			bytcode[a++] = '1';
		}
	}
	while (a != 8 && (bytcode[a++] = '0'));
	bytcode[a] = '\0';
	byte = bin_to_dec(bytcode);
	write(fd, &byte, 1);

}

int	is_bytecode(char *str)
{
	char	*sp[5] = {"live", "fork", "lfork", "zjmp", NULL};
	int	i = -1;

	while (++i != length_tab(sp)) {
		if (my_strcmp(sp[i], str) == 0)
			return (1);
	}
	return (0);
}
