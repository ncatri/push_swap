#include "push_swap.h"

t_node	*dll_create_node(int val)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (tmp)
	{
		tmp->value = val;
		tmp->index = -1;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	return (tmp);
}

void	dll_add_back(t_stack *s, t_node *new)
{
	if (!s || !new)
		return ;
	if (s->head == NULL)
	{
		s->head = new;
		s->tail = new;
		return ;
	}
	s->tail->next = new;
	new->prev = s->tail;
	new->next = NULL;
	s->tail = new;
}

void	dll_add_front(t_node **head, t_node *new)
{
	if (!head || !new)
		return ;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}

void	dll_lstfree(t_node **head)
{
	t_node	*cursor;
	t_node	*next;

	if (!head || *head == NULL)
		return ;
	cursor = *head;
	while (cursor)
	{
		next = cursor->next;
		free(cursor);
		cursor = next;
	}
	*head = NULL;
}
