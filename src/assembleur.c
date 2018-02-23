/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my.h"
#define	my_BIG_ENDIAN(num) ((num>>24)&0xff) | ((num<<8)&0xff0000) | ((num>>8)&0xff00) | ((num<<24)&0xff000000)
//ou be32toh > <endian.h>
#define FLAGS_OPEN	O_RDWR | O_APPEND | O_CREAT, 0644

header_t	init_header(char **save)
{
	header_t	header;
	int	i = -1;
	char	*name = take_header_str(save[0]);
	char	*comment = take_header_str(save[1]);

	//header.magic = my_BIG_ENDIAN(COREWAR_EXEC_MAGIC);
	header.magic = be32toh(COREWAR_EXEC_MAGIC);
	my_memset(header.prog_name, '\0', PROG_NAME_LENGTH + 1);
	while (name[++i])
		header.prog_name[i] = name[i];
	//header.prog_size = my_BIG_ENDIAN(0);
	i = -1;
	my_memset(header.comment, '\0', COMMENT_LENGTH + 1);
	while (comment[++i])
		header.comment[i] = comment[i];
	return (header);
}

int	assembleur(char *file, char **save)
{
	int	fd = open(my_strcat(find_file_name(file), ".cor"), FLAGS_OPEN);
	header_t header = init_header(save);
	int	i = -1;

	write(fd, &header, sizeof(header_t));
	while (save[++i] != NULL) {
		//printf("ligne[%d] = %s\n", i, save[i]);
		if (find_label(save[i]) == 1)
			printf("trouver label %s à [%d]\n", save[i], i);
	}
}

