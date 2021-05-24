#include "push_swap.h"

void	sort_three(t_data *data)
{
	size_t	top;
	size_t	mid;
	size_t	bottom;

	top = data->a.head->index;
	mid = data->a.head->next->index;
	bottom = data->a.tail->index;
	if (top < mid && mid < bottom && bottom > top)
		return ;
	else if (top < mid && mid > bottom && bottom > top)
	{
		swap(&data->a);
		rotate_stack(&data->a);
	}
	else if (top > mid && mid < bottom && bottom > top)
		swap(&data->a);
	else if (top < mid && mid > bottom && bottom < top)
		reverse_rotate_stack(&data->a);
	else if (top > mid && mid < bottom && bottom < top)
		rotate_stack(&data->a);
	else if (top > mid && mid > bottom && bottom < top)
	{
		swap(&data->a);
		reverse_rotate_stack(&data->a);
	}
}
