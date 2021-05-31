#include "push_swap.h"

void	throwback_values(t_stack *dst, t_stack *src)
{
	int	i;
	int	max;
	int	min;
	int best;

	max = get_target_position(src, src->index_max);
	min = get_target_position(src, src->index_min);
	best = best_to_move(max, min, src);

}

int	best_to_move(int max, int min, t_stack *s)
{
	int middle;

	middle = s->size / 2;
	if (max  )

}
			

int	get_target_position(t_stack *s, int target)
{
	t_node	*cursor;
	int		position;

	position = 0;
	cursor = s->head;
	while (cursor->index != target)
	{
		position++;
		cursor = cursor->next;
	}
	return (position);
}

void	move_target_to_top(t_stack *src, int target)
{
	int	pos;
	int j;

	pos = get_target_position(src, target);
	j = -1;
	if (pos == 1)
		swap(src);
	else if (pos <= src->size / 2)
		while (++j < pos) 
			rotate_stack(src);
	else 
		while (++j < (src->size - pos))
			reverse_rotate_stack(src);
}
