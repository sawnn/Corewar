/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my.h"

int	my_strlenchar(char *str, char c)
{
	int	i = -1;

	while (str[++i] != c);
	return (i);
}

char	*take_header_str(char *str)
{
	int	i = -1;
	int	j = my_strlen(str);

	str[j - 1] = '\0';
	while (str[++i] != 34);
	return (&str[i + 1]);
}

void	*my_memset(char *str, int c, size_t n)
{
	int	i = 0;

	for (i = 0; i != n; i++)
		str[i] = c;
	return (str);
}
