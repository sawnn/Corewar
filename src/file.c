/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my.h"

char	*find_file_name(char *str)
{
	int	i = my_strlenchar(str, '.');
	char	*file = malloc(sizeof(char) * i + 1);

	if (!str)
		return (NULL);
	file[0] = '\0';
	return (file = my_strncat(file, str, i));
}
