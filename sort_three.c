#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	size_t	top;
	size_t	mid;
	size_t	bottom;

	top = stack->head->index;
	mid = stack->head->next->index;
	bottom = stack->tail->index;
	if (top < mid && mid < bottom && bottom > top)
		return ;
	else if (top < mid && mid > bottom && bottom > top)
	{
		swap(stack);
		rotate_stack(stack);
	}
	else if (top > mid && mid < bottom && bottom > top)
		swap(stack);
	else if (top < mid && mid > bottom && bottom < top)
		reverse_rotate_stack(stack);
	else if (top > mid && mid < bottom && bottom < top)
		rotate_stack(stack);
	else if (top > mid && mid > bottom && bottom < top)
	{
		swap(stack);
		reverse_rotate_stack(stack);
	}
}

