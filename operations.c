#include "push_swap.h"

void	swap(t_node **head)
{
	t_node	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	second = (*head)->next;
	(*head)->next = second->next;
	(*head)->prev = second;
	second->next = *head;	
	second->prev = NULL;
	*head = second;
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
