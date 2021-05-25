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

void	split_two(t_data *data)
{
	int half;
	int	i;

	half = data->size / 2;
	i = 0;
	while (i < half)
	{
		move_lower_values(half, &data->b,  &data->a);
		i++;
	}
}

void	move_lower_values(int range, t_stack *dst, t_stack *src)
{
	int top;
	int bottom;
	int i;

	top = get_position_from(range, src, TOP);
	bottom = get_position_from(range, src, BOTTOM);
	i = -1;
	printf("top: %d, bottom: %d\n", top, bottom);
	if (top <= bottom)
		while (++i < top)
			rotate_stack(src);
	else
		while (++i <= bottom)
			reverse_rotate_stack(src);
	push(dst, src);

}

int	get_position_from(int range, t_stack *s, int from)
{
	t_node	*cursor;
	int		i;

	i = 0;
	if (from == TOP)
	{
		cursor = s->head;
		while (cursor)
		{
			if (cursor->index < range)
				break;
			cursor = cursor->next;
			i++;
		}
	}
	else if (from == BOTTOM)
	{
		cursor = s->tail;
		while (cursor)
		{
			if (cursor->index <= range)
				break;
			cursor = cursor->prev;
			i++;
		}
	}
	return (i);
}
