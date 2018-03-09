/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** a
*/

#include "../include/my.h"

char	*check_comment(char *str)
{
	int i = -1;

	while (str[++i] != '\0')
		if (str[i] == '#') {
			str[i] = '\0';
			return (str);
		}
	return (str);
}

int	calcule(char const *str)
{
	int i = 1;
	int k = 0;
	int check = 0;

	while (str[k] != '\0') {
		if (str[k] == '"')
			check++;
		if (check == 2)
			check = 0;
		if (check != 1 && (str[k] < 33 || str[k] > 126 || str[k] == SP)) {
			i++;
		}
		k++;
	}
	return (i);
}

char	**cut(char *s, char *pick, char **bac, int i)
{
	int k = -1;
	int j = 0;
	int a = 0;
	int check = 0;

	while (pick && bac && ++k < my_strlen(s)) {
		i = k;
		check = s[k] == '"' ? check + 1 : check;
		while (check == 1 || (s[k] >= 33 && s[k] <= 126 && s[k] != SP)) {
			pick[a++] = s[k++];
			check = s[k] == '"' ? 0 : check;
		}
		if ((s[k] < 33 && i != k) || (s[k] == SP && i != k)) {
			pick[a++] = '\0';
			bac[j++] = my_strdup(pick);
		}
		a = 0;
	}
	bac[j] = NULL;
	return (bac);
}

char	**my_str_to_word_array(char *str)
{
	char *pick = NULL;
	char **bac = NULL;
	int i = 0;

	if (str == NULL)
		return (NULL);
	str = check_comment(str);
	pick = malloc(sizeof(char) * (my_strlen(str) + 1));
	bac = malloc(sizeof(char*) * (calcule(str) + (sizeof(char*) * 2)));
	if (bac == NULL || pick == NULL)
		return (NULL);
	bac = cut(str, pick, bac, i);
	return (bac);
}
