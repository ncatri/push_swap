#include "push_swap.h"

void	print_stack(t_stack s, int data)
{
	t_node	*cursor;

	if (!s.head)
	{
		printf("(empty)\n");
		return ;
	}
	cursor = s.head;
	while (cursor)
	{
		if (data == VALUE)
			printf(" %d |", cursor->value);
		if (data == INDEX)
			printf(" %d |", cursor->index);
		cursor = cursor->next;
	}
	printf("\n");
	printf("size: %d\n", s.size);
}

void	print_rev_stack(t_stack s, int data)
{
	t_node	*cursor;

	if (!s.head)
		return ;
	cursor = s.tail;
	while (cursor)
	{
		if (data == VALUE)
			printf(" %d |", cursor->value);
		if (data == INDEX)
			printf(" %d |", cursor->index);
		cursor = cursor->prev;
	}
	printf("\n");
	printf("size: %d\n", s.size);
}
