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

	header.magic = be32toh(COREWAR_EXEC_MAGIC);
	my_memset(header.prog_name, '\0', PROG_NAME_LENGTH + 1);
	while (name[++i])
		header.prog_name[i] = name[i];
	header.prog_size = 0;
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

	write(fd, &header, sizeof(header_t));
}
