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

void	rotate_list(t_node **head)
{
	t_node	*tail;

	if (!head || !*head || !(*head)->next)
		return ;
	tail = get_tail(*head);


}
