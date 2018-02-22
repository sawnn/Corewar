/*
** EPITECH PROJECT, 2018
** v_machine.c
** File description:
** a
*/

#include "my.h"

void	mul(int fd)
{
	int i = 0;
	int j = 0;

        read(fd, &i, 4);
        read(fd, &j, 4);
        printf("%d\n", i * j);
}

void	sub(int fd)
{
	int i = 0;
        int j = 0;

        read(fd, &i, 4);
        read(fd, &j, 4);
        printf("%d\n", i - j);
}

void	add(int fd)
{
	int i = 0;
	int j = 0;

	read(fd, &i, 4);
	read(fd, &j, 4);
	printf("%d\n", i + j);
}

void	put(int fd)
{
	int lenght = 0;
	int i = -1;
	char c;

	read(fd, &lenght, 4);
	while (++i < lenght) {
		read(fd, &c, 1);
		write(1, &c, 1);
	}
}

int	virtual_machine(char *file)
{
	int fd = open(file, O_RDONLY);
	char i = 0;
	void (*cmd[5])(int);

	while (read(fd, &i, 1) != 0) {
		cmd[0] = &add;
		cmd[1] = &sub;
		cmd[2] = &mul;
		cmd[3] = &put;
		cmd[4] = NULL;
		if (i > 0 && i < 5)
			(*cmd[i - 1])(fd);
	}
	
}
