#include "push_swap.h"

void	bubble_sort(t_data *data)
{
	size_t i;

	i = 0;
	while (i < data->size )
	{
		if (data->a.head->index > data->a.head->next->index)
		{
			swap(&data->a);
			write(1, "sa\n", 3);
			print_stack(data->a, INDEX);
		}
		if (ordered(data->a))
			break;
		rotate_stack(&data->a);
		write(1, "ra\n", 3);
		print_stack(data->a, INDEX);
		i++;
	}
/*	if (!ordered(data->a))
	{
		rotate_stack(&data->a);
		write(1, "ra\n", 3);
		print_stack(data->a, INDEX);
	}
*/
}

t_bool	ordered(t_stack s)
{
	t_node	*cursor;

	cursor = s.head;
	while (cursor->next)
	{
		if (cursor->index != cursor->next->index - 1)
			return (FALSE);
		cursor = cursor->next;
	}
	return (TRUE);
}
