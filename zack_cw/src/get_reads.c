/*
** EPITECH PROJECT, 2018
** lol
** File description:
** gaspacho andalou
*/

#include "my.h"
#include "op.h"

int	find_op(int opcode, char **tab)
{
	int	i = -1;

	while (tab[++i] != NULL) {
		if (tab[i][0] == opcode + 48) {
			return (i);
		}
	}
	return (84);
}

char	find_byte(char *str)
{
	if (str[0] == '0' && str[1] == '1')
		return ('1');
	if (str[0] == '1' && str[1] == '0')
		return ('4');
	if (str[0] == '1' && str[1] == '1')
		return ('2');
	return (0);
}

char	*get_bytes(int bytecode, char c)
{
	char	*byte = NULL;
	char	*str = NULL;

	byte = getbin(bytecode);
	if ((str = malloc(sizeof(char) * 9)) == NULL)
		return (NULL);
	str = my_memset(str, '\0', 9);
	if (my_strlen(byte) != 8)
		byte = my_strcat("0", byte);
	str[0] = find_byte(my_strndup(byte, 2));
	str[1] = find_byte(my_strndup(&byte[2], 2));
	c - 48 > 2 ? str[2] = find_byte(my_strndup(&byte[4], 2))
		, str[3] = 0 : (str[2] = 0);
	return (str);
}

char	*get_reads(int	opcode, int bytecode)
{
	char	**tab = init_tab_arg(init_tab_op(tab));
	char	*str = NULL;
	char	*str2 = NULL;

	if ((str = malloc(sizeof(char) * 5)) == NULL)
		return (NULL);
	str = my_memset(str, '\0', 5);
	find_op(opcode, tab) != 84 ? str[0] = tab[find_op(opcode, tab)][1] : 0;
	str[1] = '\0';
	str2 = get_bytes(bytecode, str[0]);
	str2 = check_exception(str2, opcode);
	str2[my_strlen(str2)] = '\0';
	str = my_strcat(str, str2);
	return (str);
}

char	*get_params(int fd, int opcode, int *ret)
{
        char	*str = NULL;
	int	bytecode = 0;

	if (opcode != 9 && opcode != 1
		&& opcode != 12 && opcode != 15) {
		*ret = read(fd, &bytecode, 1);
		str = get_reads(opcode, bytecode);
	} else {
		if ((str = malloc(sizeof(char) * 5)) == NULL)
			return (NULL);
		str[0] = '1';
		opcode != 1 ? str[1] = '2' : (str[1] = '4');
	}
        return (str);
}
