/*
** EPITECH PROJECT, 2017
** list
** File description:
** list
*/

#include "../include/my.h"

char	*replace_label(char *str)
{
	char *tmp = my_strdup(str);
	int	i = my_strlen(tmp);

	tmp[i - 1] = '\0';
	tmp = my_strcat("%:", tmp);
	return (tmp);
}

t_label	*add_link(t_label *head, char *str, int i)
{
	t_label *elem = malloc(sizeof(t_label));

	if (elem == NULL)
		return (NULL);
	elem->label_name = replace_label(str);
	elem->octect = i;
	elem->next = NULL;
	if (head == NULL)
		return (elem);
	else {
		t_label	*temp = head;
		if (!temp)
			return (NULL);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = elem;
		return (head);
	}
}

int	length_list(t_label *head)
{
	int	i = 0;
	t_label	*pos = head;

	if (head == NULL)
		return (0);
	while (pos != NULL) {
		i = i + 1;
		pos = pos->next;
	}
	return (i);
}

int	delete_t_label(t_label **head, int pos)
{
	t_label	*p = (*head);
	t_label	*q = NULL;
	int	i = 0;

	if (pos == 0 || pos > length_list((*head))) {
		return (-1);
	}
	if (pos == 1) {
		(*head) = (*head)->next;
		return (0);
	}
	while (++i < pos - 1)
		p = p->next;
	q = p->next;
	p->next = q->next;
	return (0);
}
