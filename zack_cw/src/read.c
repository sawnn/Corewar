/*
** EPITECH PROJECT, 2018
** lol
** File description:
** gaspacho andalou
*/

#include "my.h"
#include "op.h"

int	*my_read(char *params, int fd, int *ret)
{
	int	i = params[0] - 48;
	int	j = 0;
	int	*p;

	if ((p = malloc(sizeof(int) * 3)) == NULL)
		return (NULL);
	while (--i >= 0 && params[j + 1]) {
		if (params[j + 1] - 48 == 2) {
			*ret = read(fd, &p[j], params[j + 1] - 48);
			p[j] = be16toh(p[j]);
		} else if (params[j + 1] - 48 == 4) {
			*ret = read(fd, &p[j], params[j + 1] - 48);
			p[j] = be32toh(p[j]);
		} else
			*ret = read(fd, &p[j], params[j + 1] - 48);
		j += 1;
	}
	return (p);
}

int	read_inst(t_champ *champ)
{
	char	*params = NULL;
	int	*param;
	int	ret = 1;
	int	opcode = 1;

	while (ret > 0) {
		ret = read(champ->fd, &opcode, 1);
		params = get_params(champ->fd, opcode, &ret);
		param = my_read(params, champ->fd, &ret);
		//printf("op %d params %s\np1 %d p2 %d p3 %d\n\n", opcode, params, param[0], param[1], param[2]);
	}
	return (0);
}
