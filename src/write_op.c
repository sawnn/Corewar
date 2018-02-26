/*
** EPITECH PROJECT, 2018
** write_op.c
** File description:
** a
*/

#include "../include/my.h"

int	write_arg(char *arg, int fd, int *octet)
{
	int i = -1;
	int nbr = 0;

	if (arg[++i] == 'r') {
		nbr = my_getnbr(&arg[1]);
		*octet = 1;
	}
	else if (arg[i] == '%') {
		nbr = my_getnbr(&arg[1]);
		*octet = 4;
		nbr = be32toh(nbr);
	}
	else {
		nbr = my_getnbr(arg);
		*octet = 2;
		nbr = be16toh(nbr);
	}
	return (nbr);
}

int	write_op(char ***all, int fd, int i, int j)
{
	t_op ope;
	int op = 0;
	int octet = 1;

	if (init_struct(&ope) == 84)
		return (84);
	while (all[++i] != NULL) {
		if (all[i][0][my_strlen(all[i][0]) - 1] == LABEL_CHAR)
			j = 0;
		if (all[i][j + 1] != NULL) {
			op = send_op(ope, &all[i][++j]);
			write(fd, &op, octet);
		}
		while (all[i][++j] != NULL) {
			op = write_arg(all[i][j], fd, &octet);
			write(fd, &op, octet);
		}
		octet = 1;
		j = -1;
	}
}
