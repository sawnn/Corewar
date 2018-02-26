/*
** EPITECH PROJECT, 2018
** write_op.c
** File description:
** a
*/

#include "../include/my.h"

int	write_arg(char *arg, int fd, int *octet, char *ope)
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
		if (is_special_case(ope) == 1) {
			*octet = 2;
			nbr = be16toh(nbr);
		}
		else	
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
	char *str;

	if (init_struct(&ope) == 84)
		return (84);
	while (all[++i] != NULL) {
		j = all[i][0][my_strlen(all[i][0]) - 1] == LABEL_CHAR ? 0 : j;
		if (all[i][j + 1] != NULL) {
			op = send_op(ope, &all[i][++j]);
			str = my_strdup(all[i][j]);
			write(fd, &op, octet);
		}
		while (all[i][++j] != NULL) {
			op = write_arg(all[i][j], fd, &octet, str);
			write(fd, &op, octet);
		}
		octet = 1;
		j = -1;
	}
}

int	write_file(char ***all, t_label *label, int fd)
{
	write_op(all, fd, -1, -1);
	return (0);
}
