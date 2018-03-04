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

void	init_header(char **save, int fd, int size)
{
	header_t	header;
	int	i = -1;
	char	*name = take_header_str(save[0]);
	char	*comment = take_header_str(save[1]);
	
	memset(&header, 0, sizeof(header_t));
	header.magic = little_to_big_endian(COREWAR_EXEC_MAGIC);
	header.prog_size = little_to_big_endian(size);
//header.magic = my_BIG_ENDIAN(COREWAR_EXEC_MAGIC);
//	header.magic = be32toh(COREWAR_EXEC_MAGIC);
//	header.prog_size = be32toh(size);
	my_memset(header.prog_name, '\0', PROG_NAME_LENGTH + 1);
	
	while (name[++i])
		header.prog_name[i] = name[i];
//	header.prog_name[i] = '\0';
	//header.prog_size = my_BIG_ENDIAN(size);
	//header.prog_size = my_BIG_ENDIAN(0);
	i = -1;
	my_memset(header.comment, '\0', COMMENT_LENGTH + 1);
	while (comment[++i])
		header.comment[i] = comment[i];
	//printf("%d\n", my_strlen(header.comment));
	//while (headre = comm ++i)
	//header.comment[i] = '\0';
	//printf("name = %s, comment = %s %d\n", header.prog_name, header.comment, i);
	//
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

	//octect += 8 ? //verifier cas speciaux
	//olabel[1] = -1;
	if (fd == -1 || all == NULL)
		return (84);
	while (all[++i] != NULL) {
//		printf("octect ich turn = %d - str = %s\n", octect, all[i][0]);
		if (is_label_to_save(all[i]) == 1) {
			olabel[(k++)] = octect;
			olabel = realloc(olabel, sizeof(int) * (k + 1));
		}
		if (find_label(all[i][0]) == 1) {
			if ((label = add_link(label, all[i][0], octect)) == NULL)
				return (84);
			octect += find_octect_line(all[i], 1, &olabel);
		}
		else
			octect += find_octect_line(all[i], 0, &olabel);
	}
	olabel[k] = -1;
//	printf("OCTECT FINAL = %d - bigendian = %d\n", octect, be32toh(octect));
//	print_list(label);
	init_header(save, fd, octect);
//	print_int(olabel);
	write_file(all, label, fd, olabel);
	return (0);
}
