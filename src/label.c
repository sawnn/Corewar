/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my.h"
/*
int	which_arg_is(char *str)
{
	int	i = -1;

	while (str[++i] != ' ')
	
}
*/
int	find_label(char *str)
{
	int	i = my_strlen(str);

	if (str[i - 1] == LABEL_CHAR)
		return (1);
	return (0);
}
/*
int	find_octect_line(char *str, int fd)
{
	char	c = 0;
	t_op ope;
	char	**instruc = my_str_to_word_array(str);
	int	octect = 0;

	init_op(&op);
	octect += 2; // pour op code et bytecodes
	
	printf("char = %c\n", c);
}
*/
