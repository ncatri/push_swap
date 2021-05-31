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
	int	i;
	int	parts;
	int range;

	printf("stack a:\n");
	print_stack(data->a, INDEX);
	printf("stack b:\n");
	print_stack(data->b, INDEX);

	i = 1;
	parts = get_division(data->size);
	while (i <= parts)
	{
		range = get_range(data->size, parts, i);
		printf("range: %d\n", range);
		move_lower_values(range - 1, &data->b,  &data->a);
		printf("stack a:\n");
		print_stack(data->a, INDEX);
		printf("stack b:\n");
		print_stack(data->b, INDEX);
		i++;
	}

//	printf("stack a:\n");
//	print_stack(data->a, INDEX);
//	printf("stack b:\n");
//	print_stack(data->b, INDEX);

//	printf("move_highest:\n");
//	move_highest(&data->a, &data->b);
}

int	get_range(size_t size, int part, int i)
{
	float	frange;

	frange = i * size / (float)part;
	if (frange - (int)frange >= 0.5)
		return ((int)frange + 1);
	else
		return (frange);
}

int	get_division(size_t size)
{
	int div;
	size_t	i;

	i = 0;
	while (i * i <= size)
		i++;
	div = i / 2;
	return (div);
}

void	move_lower_values(int range, t_stack *dst, t_stack *src)
{
	int top;
	int bottom;
	int j;

	top = 0;
	while (top != -1)
	{
		top = get_position_from_top(range, src);
		bottom = get_position_from_bottom(range, src);
		j = -1;
//		printf("top: %d, bottom: %d\n", top, bottom);
		if (top <= bottom)
			while (++j < top)
				rotate_stack(src);
		else
			while (++j <= bottom)
				reverse_rotate_stack(src);
		if (top != -1)
			push(dst, src);
	}
}

int	get_position_from_top(int range, t_stack *s)
{
	t_node	*cursor;
	int		i;
	t_bool	found;

	i = -1;
	found = FALSE;
	cursor = s->head;
	while (cursor && !found)
	{
		if (cursor->index <= range)
			found = TRUE;	
		cursor = cursor->next;
		i++;
	}
	if (found)
		return (i);
	else
		return (-1);
}


int	get_position_from_bottom(int range, t_stack *s)
{
	t_node	*cursor;
	int		i;
	t_bool	found;

	i = -1;
	found = FALSE;
	cursor = s->tail;
	while (cursor && !found)
	{
		if (cursor->index <= range)
			found = TRUE;
		cursor = cursor->prev;
		i++;
	}
	if (found)
		return (i);
	else
		return (-1);
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
