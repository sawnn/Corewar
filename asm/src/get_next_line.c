/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my.h"

int	my_strlen(char *str)
{
	int	i = -1;

	while (str[++i] != '\0');
	return (i);
}

char	*my_strcat(char *s1, char *s2)
{
	char	*tmp = NULL;
	int	i = 0;
	int	j = 0;
	int	c = my_strlen(s1) + my_strlen(s2) + 2;

	if ((tmp = malloc(sizeof(char) * c)) != NULL) {
		while (s1[i] != '\0') {
			tmp[i] = s1[i];
			i = i + 1;
		}
		while (s2[j] != '\0') {
			tmp[i] = s2[j];
			i = i + 1;
			j = j + 1;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}

 char	*my_strncat(char *dest, char *src, int nb)
{
	int i = 0;
	int t1 = -1;

	while (dest[++t1] != '\0');
	while (i < nb && src[i]) {
		dest[t1 + i] = src[i];
		i++;
	}
	dest[t1 + i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char	buff[READ_SIZE];
	int	i = 0;
	int	j = 0;
	char	*ret;

	if ((ret = malloc(sizeof(char) * 1)) == NULL || fd == -1)
		return (NULL);
	ret[i] = '\0';
	while (13) {
		if ((read(fd, buff, READ_SIZE)) == 0)
			return (NULL);
		else if (buff[i] != '\0' && buff[i] != '\n') {
			ret = my_strcat(ret, buff);
			j = j + 1;
		}
		else {
			ret[j] = '\0';
			return (ret);
		}
	}
}
