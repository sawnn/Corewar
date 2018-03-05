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
	int	j = strlen_slash(str);

	if (j == -1) {
		if (!str)
			return (NULL);
		file[0] = '\0';
		return (file = my_strncat(file, str, i));
	}
	file[0] = '\0';
	str = my_strdup(&str[j + 1]);
	i = my_strlenchar(str, '.');
	file = malloc(sizeof(char) * (i + 1));
	file[0] = '\0';
	str[i] = '\0';
	return (file = my_strncat(file, str, i));
}
