/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my.h"

int	find_octect_line(char **tab, int pos, int **olabel)
{
	int	octect = 0;
	int	i = pos + 1;

	if (tab[1] == NULL)
		return (0);
	octect += 2;
	is_remove_bytecode(tab[pos], &octect);
	while (i != length_tab(tab)) {
		if (is_special_case(tab[pos]) == 1)
			which_arg_is_special(tab[i], &octect);
		else {
			which_arg_is(tab[i]) == 1 ? octect += REG_SIZE : 0;
			which_arg_is(tab[i]) == 2 ? octect += DIR_SIZE : 0;
			which_arg_is(tab[i]) == 3 ? octect += IND_SIZE : 0;
		}
		i++;
	}
	return (octect);
}

void	init_header(char **save, int fd, int size)
{
	header_t	header;
	int	i = -1;
	char	*name = take_header_str(save[0]);
	char	*comment = take_header_str(save[1]);

	memset(&header, 0, sizeof(header_t));
	header.magic = little_to_big_endian(COREWAR_EXEC_MAGIC);
	header.prog_size = little_to_big_endian(size);
	my_memset(header.prog_name, '\0', PROG_NAME_LENGTH + 1);
	while (name[++i])
		header.prog_name[i] = name[i];
	i = -1;
	my_memset(header.comment, '\0', COMMENT_LENGTH + 1);
	while (comment[++i])
		header.comment[i] = comment[i];
	write(fd, &header, sizeof(header_t));
}

int	assembleur(char *file, char **save)
{
	int	fd = open(my_strcat(find_file_name(file), ".cor"), FLAGS_OPEN);
	int	i = -1;
	char	***all = fill_all_tab(all, save);
	int	octect = 0;
	t_label	*label = NULL;
	int	*olabel = malloc(sizeof(int) * 1);
	int	k = 0;

	if (fd == -1 || all == NULL)
		return (84);
	while (all[++i] != NULL) {
		if (is_label_to_save(all[i]) == 1) {
			olabel[(k++)] = octect;
			olabel = realloc(olabel, sizeof(int) * (k + 1));
		}
		if (find_label(all[i][0]) == 1) {
			label = add_link(label, all[i][0], octect);
			octect += find_octect_line(all[i], 1, &olabel);
		} else
			octect += find_octect_line(all[i], 0, &olabel);
	}
	olabel[k] = -1;
	init_header(save, fd, octect);
	write_file(all, label, fd, olabel);
}
