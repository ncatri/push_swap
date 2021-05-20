#include "push_swap.h"

t_node	*dll_create_node(int val)
{
	t_node *tmp;

	tmp = malloc(sizeof(t_node));
	if (tmp)
	{
		tmp->value = val;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	return (tmp);
}

void	dll_add_back(t_stack *s, t_node *new)
{
	t_node	*cursor;

	if (!s|| !new)
		return ;
	if (s->head == NULL)
	{
		s->head = new;
		return ;
	}
	cursor = s->head;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = new;
	new->prev = cursor;
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

/* debug */

void	print_stack(t_stack s)
{
	t_node	*cursor;

	if (!s.head)
		return ;
	cursor = s.head;
	while (cursor)
	{
		printf(" %d |", cursor->value);
		cursor = cursor->next;
	}
	printf("\n");
}

void	print_rev_stack(t_stack s)
{
	t_node *cursor;

	if (!s.head)
		return ;
	cursor = s.tail; 
	while (cursor)
	{
		printf(" %d |", cursor->value);
		cursor = cursor->prev;
	}
	printf("\n");
}
