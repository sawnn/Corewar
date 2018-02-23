/*
** EPITECH PROJECT, 2018
** a
** File description:
** a
*/

#include "../include/my.h"

int	send_op(int fd, t_op ope, char **instruc)
{
	int	i = -1;

	while (ope.tab[++i] != NULL) {
		if (my_strcmp(instruc[0], ope.tab[i]) == 0) {
			return (i + 1);
		}
	}
}

int	init_struct(t_op *ope)
{
	if (init_op(ope) == 84)
		return (84);
	if (init_ac(ope) == 84)
		return (84);
	if (init_arg(ope) == 84)
		return (84);
	ope->isempty = 0;
}

char	**check_label(char **save, t_op ope)
{
	int i = -1;
	int j = -1;

	while (ope.isempty == 1 && ope.check_lab[++i] != NULL) {
		while (ope.label[++j] != NULL
			&& my_strcmp(ope.label[j], ope.check_lab[i]) != 0);
		if (ope.label[j] == NULL)
			return (NULL);
		j = -1;
	}
	return (save);
}

char	**parseur(char *str, char *str2, int j, char *s)
{
	int fd2 = open(str, O_RDONLY);
	t_op ope;
	char **save;
	char **instruc;

	if (init_struct(&ope) == 84 || fd2 == -1
	|| (save = check_header(fd2, save, 0)) == NULL)
		return (NULL);
	while ((s = get_next_line(fd2))) {
		if (s[0] != '\0' && (instruc = my_str_to_word_array(s)) == NULL)
			return (NULL);
		if (s[0] != '\0' && instruc[0] != NULL && HELP)
			return (NULL);
		else if (s[0] != '\0' && instruc[0] != NULL) {
			save[j++] = my_strdup(s);
			save = realloc(save, sizeof(char *) * (j + 1));
		}
	}
	save[j] = NULL;
	return (check_label(save, ope));
}
