/*
** EPITECH PROJECT, 2018
** lol
** File description:
** gaspacho andalou
*/

#include "my.h"
#include "op.h"

t_champ	*fill_champion(t_champ *champion, int fd, char *filename)
{
	t_champ	*tmp;
	header_t header;

	if ((tmp = malloc(sizeof(t_champ))) == NULL)
		return (NULL);	
	read(fd, &header, sizeof(header_t));
	tmp->fd = fd;
	tmp->file = filename;
	tmp->header = header;
	tmp->name = header.prog_name;
	tmp->prog_size = header.prog_size;
	tmp->comment = header.comment;
	tmp->next = champion;
	return (tmp);
}

int	init_game(int ac, char **av, char *vm)
{
	int	i = 0;
	int	fd = 0;
	header_t header;
	t_champ *champion = NULL;
	t_pc	*pc = NULL;

	while (++i < ac) {
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			return (84);
		champion = fill_champion(champion, fd, av[i]);
		champion->number = i;
	}
	set_pc(champion, pc, i - 1);
	read_inst(champion, vm, champion->pc);
//load_battlefield(vm);
	return (0);
}

int	main(int ac, char **av)
{
	char	*vm = NULL;

	if ((vm = malloc(sizeof(char) * MEM_SIZE)) == NULL)
		return (84);
	vm = my_memset(vm, '\0', MEM_SIZE);
	if (handle_error(ac, av) == 84 || init_game(ac, av, vm) == 84)
		return (84);
	//while (CYCLE_TO_DIE != 0) {
	//	cycle(1);
	//}
	return (0);
}
