#include "push_swap.h"

void	throwback_max_min(t_stack *dst, t_stack *src)
{
	int	max;
	int	min;
	int	best;

	max = get_target_position(src, src->index_max);
	min = get_target_position(src, src->index_min);
	best = best_to_move(max, min, src);
	if (best == MAX)
	{
		move_target_to_top(src, src->index_max);
		src->index_max--;
	}
	else
	{
		move_target_to_top(src, src->index_min);
		src->index_min++;
	}
	push(dst, src, VERBOSE);
	if (best == MIN && dst->size > 1)
		rotate_stack(dst, VERBOSE);
}

void	throwback_max(t_stack *dst, t_stack *src)
{
	move_target_to_top(src, src->index_max);
	src->index_max--;
	push(dst, src, VERBOSE);
}

int	best_to_move(int max, int min, t_stack *s)
{
	int	moves_max_top;
	int	moves_min_top;

	moves_max_top = get_moves_to_top(max, s);
	moves_min_top = get_moves_to_top(min, s);
	if (moves_max_top <= moves_min_top)
		return (MAX);
	else
		return (MIN);
}

int	get_moves_to_top(int position, t_stack *s)
{
	int	moves;
	int	middle;

	middle = s->size / 2;
	if (middle - position > 0 || \
			(middle - position == 0 && s->size - middle > middle))
		moves = position;
	else
		moves = s->size - position;
	return (moves);
}

int	get_target_position(t_stack *s, int target)
{
	t_node	*cursor;
	int		position;

	position = 0;
	cursor = s->head;
	while (cursor && cursor->index != target)
	{
		position++;
		cursor = cursor->next;
	}
	return (position);
}

void	move_target_to_top(t_stack *src, int target)
{
	int	pos;
	int	j;

	pos = get_target_position(src, target);
	j = -1;
	if (pos == 1)
		swap(src, VERBOSE);
	else if (pos <= src->size / 2)
		while (++j < pos)
			rotate_stack(src, VERBOSE);
	else
		while (++j < (src->size - pos))
			reverse_rotate_stack(src, VERBOSE);
}
