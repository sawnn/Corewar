/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my.h"

char	***fill_all_tab(char ***all, char **save)
{
	int	j = -1;
	int	o = 1;

	all = malloc(sizeof(char **) * length_tab(save) + sizeof(char **));
	if (!all)
		return (NULL);
	while (++j != length_tab(save) - 2)
		all[j] = my_str_to_word_array(save[++o]);
	all[j] = NULL;
	return (all);
}

char	*take_header_str(char *str)
{
	int	i = -1;
	char **tmp = my_str_to_word_array(str);
	int	j = my_strlen(tmp[1]);

	tmp[1][j - 1] = '\0';
	while (tmp[1][++i] != 34);
	return (&tmp[1][i + 1]);
}

void	*my_memset(char *str, char c, size_t n)
{
	int	i = 0;

	for (i = 0; i <= n; i++)
		str[i] = c;
	return (str);
}
