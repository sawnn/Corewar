/*
** EPITECH PROJECT, 2018
** write_op.c
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
	int i = -1;
	int o = 0;
	char bytcode[8];

	while (arg[++i] != NULL) {
		if (arg[i][0] == 'r') {
			bytcode[o++] = '0';
			bytcode[o++] = '1';
		}
		else if (arg[i][0] == DIRECT_CHAR) {
			bytcode[o++] = '1';
			bytcode[o++] = '0';
		}
		else {
			bytcode[o++] = '1';
			bytcode[o++] = '1';
		}
	}
	while (o != 8)
		bytcode[o++] = '0';
	bytcode[o] = '\0';
	int byte = bin_to_dec(bytcode);
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

int	write_arg(char *arg, int fd, int *octet, char *ope)
{
	int i = -1;
	int nbr = 0;

	if (arg[++i] == 'r') {
		nbr = my_getnbr(&arg[1]);
		*octet = 1;
	}
	else if (arg[i] == DIRECT_CHAR) {
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
			if (is_bytecode(all[i][j]) == 0)
				get_bytecode(&all[i][j + 1], fd);
		}
		while (all[i][++j] != NULL) {
			op = write_arg(all[i][j], fd, &octet, str);
			write(fd, &op, octet);
		}
		octet = 1;
		j = -1;
	}
}

char	*index_o(char *str, t_label *label, int *olabel, int j)
{
	int	i = -1;
	int nbr = 0;
	static int k = -1;
	char *tmp;
	t_label	*tmp2 = label;

	while (tmp2 != NULL) {
		if (my_strcmp(tmp2->label_name, str) == 0) {
			nbr = ((olabel[++k] - tmp2->octect) * -1);
			tmp = my_getstr(nbr);
			return (tmp);
		}
		tmp2 = tmp2->next;
	}
}

char	***change_label(char ***all, t_label *label, int *olabel)
{
	int i = -1;
	int j = -1;
	char *tmp = malloc(sizeof(char) * 2);

	tmp[0] = DIRECT_CHAR;
	tmp[1] = '\0';
	while (all[++i] != NULL) {
		while (all[i][++j] != NULL) {
			if (all[i][j][0] == DIRECT_CHAR && all[i][j][1] == LABEL_CHAR)
				all[i][j] = index_o(all[i][j], label, olabel, j);
			else if (all[i][j][0] == LABEL_CHAR) {
				tmp = my_strcat(tmp, all[i][j]);
				tmp = index_o(tmp, label, olabel, j);
				all[i][j] = my_strdup(&tmp[1]);
					tmp[0] = DIRECT_CHAR;
					tmp[1] = '\0';
			}
			
		}
		j = -1;
	}
	return (all);
}

int	write_file(char ***all, t_label *label, int fd, int *olabel)
{
	all = change_label(all, label, olabel);
	write_op(all, fd, -1, -1);
	return (0);
}
