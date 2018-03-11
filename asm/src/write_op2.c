/*
** EPITECH PROJECT, 2018
** write op 2
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

void	write_op_bis(int *i, int *j, t_op *ope, char ***all)
{
	int	 op = 0;
	int	octet = 1;
	char	*str;
	int	fd = *j;

	*j = -1;
	*j = all[*i][0][my_strlen(all[*i][0]) - 1] == LABEL_CHAR ? 0 : *j;
	if (all[*i][*j + 1] != NULL) {
		op = send_op(*ope, &all[*i][++(*j)]);
		str = my_strdup(all[*i][*j]);
		write(fd, &op, octet);
		is_bytecode(all[*i][*j]) == 0 ?
			get_bytecode(&all[*i][*j + 1], fd) : 0;
	}
	while (all[*i][++(*j)] != NULL) {
		op = write_arg(all[*i][*j], fd, &octet, str);
		write(fd, &op, octet);
	}
	octet = 1;
}

int	write_op(char ***all, int fd, int i, int j)
{
	t_op	ope;

	if (init_struct(&ope) == 84)
		return (84);
	while (all[++i] != NULL) {
		j = fd;
		write_op_bis(&i, &j, &ope, all);
	}
}
