/*
** EPITECH PROJECT, 2018
** handle error
** File description:
** gaspacho andalou
*/

#include "my.h"

int	check_ext(char	*str)
{
	int	i = -1;

	while (str[++i] != '\0');
	i -= 4;
	str = &str[i];
	if (my_strcmp(str, ".cor") == 84)
		return (84);
	return (0);
}

int	handle_error(int ac, char **av)
{
	int	i = 0;
	char	*str = NULL;

	if (ac < 2)
		return (84);
	while (av[++i] != NULL) {
		if (check_ext(str = my_strdup(av[i])) == 84)
			return (84);
	}
}
