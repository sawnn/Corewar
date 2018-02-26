/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my.h"
#define	my_BIG_ENDIAN(num) ((num>>24)) | ((num<<8)&0xff0000) | ((num>>8)&0xff00) | ((num<<24)&0xff000000)
//ou be32toh > <endian.h>
#define FLAGS_OPEN	O_RDWR | O_TRUNC | O_CREAT, 0644

void	init_header(char **save, int fd)
{
	header_t	header;
	int	i = -1;
	char	*name = take_header_str(save[0]);
	char	*comment = take_header_str(save[1]);

	//header.magic = little_to_big_endian(COREWAR_EXEC_MAGIC);
	//header.magic = my_BIG_ENDIAN(COREWAR_EXEC_MAGIC);
	header.magic = be32toh(COREWAR_EXEC_MAGIC);
	my_memset(header.prog_name, '\0', PROG_NAME_LENGTH + 1);
	while (name[++i])
		header.prog_name[i] = name[i];
	//header.prog_size = little_to_big_endian(0);
	header.prog_size = be32toh(0);
	//header.prog_size = my_BIG_ENDIAN(0);
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

	//octect += 8 ? //verifier cas speciaux
	if (fd == -1 || all == NULL)
		return (84);
	init_header(save, fd);
	while (all[++i] != NULL) {
//		printf("octect ich turn = %d - str = %s\n", octect, all[i][0]);
		if (find_label(all[i][0]) == 1) {
			label = add_link(label, all[i][0], octect);
			octect += find_octect_line(all[i], 1);
		}
		else
			octect += find_octect_line(all[i], 0);
	}
//	printf("OCTECT FINAL = %d\n", octect);
//	print_list(label);
}
