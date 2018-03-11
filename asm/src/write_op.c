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
	} else if (arg[i] == '%') {
		nbr = my_getnbr(&arg[1]);
		*octet = 4;
		if (is_special_case(ope) == 1) {
			*octet = 2;
			nbr = be16toh(nbr);
		} else
			nbr = be32toh(nbr);
	} else {
		nbr = my_getnbr(arg);
		*octet = 2;
		nbr = be16toh(nbr);
	}
	return (nbr);
}

char	*indexo(char *str, t_label *label, int *olabel, int j)
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

void	change_label_bis(int *i, int *j, t_label *lbl, PARAM)
{
	char *tmp = NULL;

	if ((tmp = malloc(sizeof(char) * 2)) == NULL)
		return;;
	if (tmp == NULL) {
		tmp[0] = DIRECT_CHAR;
		tmp[1] = '\0';
	}
	if (all[*i][*j][0] == DIRECT_CHAR && all[*i][*j][1] == ':')
		all[*i][*j] = indexo(all[*i][*j], lbl, olbl, *j);
	else if (all[*i][*j][0] == LABEL_CHAR) {
		tmp = my_strcat(tmp, all[*i][*j]);
		tmp = indexo(tmp, lbl, olbl, *j);
		all[*i][*j] = my_strdup(&tmp[1]);
		tmp[0] = DIRECT_CHAR;
		tmp[1] = '\0';
	}
}

char	***change_label(char ***all, t_label *label, int *olabel)
{
	int i = -1;
	int j = 0;

	while (all[++i] != NULL) {
		while (all[i][++j] != NULL) {
			change_label_bis(&i, &j, label, olabel, all);
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
