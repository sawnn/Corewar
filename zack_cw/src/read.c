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

char	*put_int_char(int *p, char *vm, int *i)
{
	int	j = -1;
	while (++j < 4) {
		if (p[j] <= 255) {
			printf("1 p %d\n", p[j]);
			vm[(*i)++] = p[j];
		}
		else if (p[j] <= 65535) {
			printf("2 p %d\n", p[j]);
			vm[(*i)++] = (p[j] >> 8) & 0xFF;
			vm[(*i)++] = p[j] & 0xFF;
		}
		else if (p[j] <= 16777215) {
			printf("3 p %d\n", p[j]);
			vm[(*i)++] = (p[j] >> 24) & 0xFF;
			vm[(*i)++] = (p[j] >> 16) & 0xFF;
			vm[(*i)++] = (p[j] >> 8) & 0xFF;
			vm[(*i)++] = p[j] & 0xFF;
		}
	}
	return (vm);
}

int	read_inst(t_champ *champ, char *vm, int i)
{
	char	*params = NULL;
	int	*param;
	int	ret = 1;
	int	j = -1;
	int	opcode = 1;

	while (ret > 0) {
		ret = read(champ->fd, &vm[i], 1);
		params = get_params(champ->fd, opcode, &ret);
		param = my_read(params, champ->fd, &ret);
		i += 1;
		vm = put_int_char(param, vm, &i);
		printf("vm %d\n", vm[i]);
//printf("op %d params %s\np1 %d p2 %d p3 %d\n\n", opcode, params, param[0], param[1], param[2]);
		i += 1;
	}
	return (0);
}
