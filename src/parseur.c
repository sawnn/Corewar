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

void	write_op(t_op ope, int fd, char **instruc)
{
	int	i = send_op(fd, ope, instruc);
	int	j;
	int	k;
	int	x = -1;

	if (i == 4) {
		k = my_strlen(instruc[1]);
		write(fd, &i, 1);
		write(fd, &k, 4);
		while (++x < my_strlen(instruc[1])) {
			j = instruc[1][x];
			write(fd, &j, 1);
		}
		return;
	}
	j = my_getnbr(instruc[1]);
	k = my_getnbr(instruc[2]);
	write(fd, &i, 1);
	write(fd, &j, 4);
	write(fd, &k, 4);
}

int	init_struct(t_op *ope)
{
	if (init_op(ope) == 84)
		return (84);
	if (init_ac(ope) == 84)
		return (84);
	if (init_arg(ope) == 84)
		return (84);
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
		if (s[0] != '\0' && instruc[0] != NULL && check_error(ope, instruc) == 84)
			return (NULL);
		else if (s[0] != '\0' && instruc[0] != NULL) {
			save[j++] = my_strdup(s);
			save = realloc(save, sizeof(char *) * (j + 1));
		}
	}
	save[j] = NULL;
	return (save);
}
