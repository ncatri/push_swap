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
	move_lower_values(half, &data->b,  &data->a);
	move_lower_values(data->size, &data->b, &data->a);

//	printf("stack a:\n");
//	print_stack(data->a, INDEX);
//	printf("stack b:\n");
//	print_stack(data->b, INDEX);

//	printf("move_highest:\n");
	move_highest(&data->a, &data->b);
}

void	move_lower_values(int range, t_stack *dst, t_stack *src)
{
	int top;
	int bottom;
	int i;
	int j;

	i = 0;
	while (i < range)
	{
		top = get_position_from(range, src, TOP);
		bottom = get_position_from(range, src, BOTTOM);
		j = -1;
//		printf("top: %d, bottom: %d\n", top, bottom);
		if (top <= bottom)
			while (++j < top)
				rotate_stack(src);
		else
			while (++j <= bottom)
				reverse_rotate_stack(src);
		push(dst, src);
		i++;
	}
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
			if (cursor->index < range)
				break;
			cursor = cursor->prev;
			i++;
		}
	}
	return (i);
}

void	move_highest(t_stack *dst, t_stack *src)
{
	int	pos;
	int j;

	while (src->size)
	{
		pos = get_max_position(src);
		j = -1;
		if (pos == 1)
			swap(src);
		else if (pos <= src->size / 2)
			while (++j < pos) 
				rotate_stack(src);
		else 
			while (++j < (src->size - pos))
				reverse_rotate_stack(src);
		push(dst, src);
	}
}

int	get_max_position(t_stack *s)
{
	int pos;
	t_node *cursor;

	pos = 0;
	cursor = s->head;
	while (cursor)
	{
		if (cursor->index == s->size -1)
			break;
		cursor = cursor->next;
		pos++;
	}
	return (pos);
}
