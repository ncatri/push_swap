#include "push_swap.h"

void	split_two(t_data *data)
{
	int	i;
	int	parts;
	int	range;

	i = 1;
	parts = get_division(data->size);
	while (i <= parts)
	{
		range = get_range(data->size, parts, i);
		move_lower_values(range - 1, &data->b, &data->a);
		i++;
	}
	data->b.index_max = data->size - 1;
	data->b.index_min = 0;
	while (data->b.head != NULL)
		throwback_max(&data->a, &data->b);
	if (get_target_position(&data->a, data->a.index_min) > data->a.size / 2)
		while (data->a.head->index != 0)
			reverse_rotate_stack(&data->a, VERBOSE);
	else
		while (data->a.head->index != 0)
			rotate_stack(&data->a, VERBOSE);
}

void	move_lower_values(int range, t_stack *dst, t_stack *src)
{
	int	top;
	int	bottom;
	int	j;

	top = 0;
	while (top != -1)
	{
		top = get_position_from_top(range, src);
		bottom = get_position_from_bottom(range, src);
		j = -1;
		if (top <= bottom)
			while (++j < top)
				rotate_stack(src, VERBOSE);
		else
			while (++j <= bottom)
				reverse_rotate_stack(src, VERBOSE);
		if (top != -1)
			push(dst, src, VERBOSE);
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
