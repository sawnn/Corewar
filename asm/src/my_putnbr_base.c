/*
** EPITECH PROJECT, 2018
** my_putnbr_base
** File description:
** a
*/

#include "../include/my.h"

int	my_getnbr(char *str)
{
	int	i = 0;
	int	j = 0;

	if (str[0] == '-')
		i = i + 1;
	while (str[i]) {
		j = j + str[i++] - 48;
		j = j * 10;
	}
	j = j / 10;
	if (str[0] == '-')
		j = j * -1;
	return (j);
}

char	*my_putnbr_base(unsigned int nbr, char *base)
{
	int i = -1;
	int chara = 0;
	static int cmpt = -1;
	static char str[10000];

	while (base[++i] != '\0');
	if (nbr > 0) {
		chara = nbr % i;
		nbr /= i;
		my_putnbr_base(nbr, base);
		str[++cmpt] = base[chara];
		str[cmpt + 1] = '\0';
	}
	else
		cmpt = -1;
	return (str);
}
