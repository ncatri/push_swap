#include "push_swap.h"

void	swap(t_stack *s)
{
	t_node	*second;

	if (!s || !s->head || !s->head->next)
		return ;
	second = s->head->next;
	s->head->next = second->next;
	s->head->prev = second;
	second->next = s->head;	
	second->prev = NULL;
	s->head = second;
}

void	rotate_stack(t_stack *s)
{
	t_node	*new_tail;

	if (!s || !s->head || s->head == s->tail)
		return ;
	new_tail = s->tail->prev;
	s->tail->next = s->head;
	s->tail->prev = NULL;
	s->head->prev = s->tail;	
	s->head = s->tail;
	s->tail = new_tail;
	s->tail->next = NULL;
}

/* maybe not needed */
t_node	*get_tail(t_node *head)
{
	t_node	*cursor;

	if (!head)
		return (NULL);
	cursor = head;
	while (cursor->next)
		cursor = cursor->next;
	return (cursor);
}
