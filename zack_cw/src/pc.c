/*
** EPITECH PROJECT, 2018
** pc
** File description:
** gaspacho andalou
*/

#include "my.h"
#include "op.h"

t_pc	*new_pc(t_pc *pc, int nbr, int pos)
{
	t_pc	*tmp = NULL;

	if ((tmp = malloc(sizeof(t_pc))) == NULL)
		return (NULL);
	tmp->pc = pos;
	tmp->prog_nbr = nbr;
	tmp->next = pc;
	return (tmp);
}

int	set_pc(t_champ *champ, t_pc *pc, int nb_players)
{
	int	mem = MEM_SIZE;
	int	dist = MEM_SIZE / nb_players;

	while (champ) {
		pc = new_pc(pc, champ->number, mem - dist);
		champ->pc = pc->pc;
		mem -= dist;
		champ = champ->next;
	}
	return (0);
}
