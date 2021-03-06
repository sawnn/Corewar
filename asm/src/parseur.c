/*
** EPITECH PROJECT, 2018
** a
** File description:
** a
*/

#include "../include/my.h"

int	check_error(t_op *ope, char **instruct)
{
	int i = -1;
	int j = 0;
	int k = 0;

	if ((i = check_name(ope, instruct, 0, -1)) == 84)
		return (84);
	if (i == -1)
		return (i);
	if (instruct[0][my_strlen(instruct[0]) - 1] == LABEL_CHAR)
		k = 1;
	if ((i = check_ac(ope, instruct, i, k)) == 84)
		return (84);
	return (i);
}

int	send_op(t_op ope, char **instruc)
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
	return (check_label(save, ope, -1, -1));
}
