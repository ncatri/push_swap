#include "push_swap.h"

int	fill_array(t_data *data)
{
	t_node	*cursor;
	size_t	i;

	data->array = malloc(sizeof(int) * data->size);
	if (!data->array)
		return (FAIL);
	cursor = data->a.head;
	i = 0;
	while (cursor)
	{
		data->array[i] = cursor->value;
		cursor = cursor->next;
		i++;
	}
	return (SUCCESS);
}

/*
 * inputs:	- argument count from main
 * 			- pointer to stacks
 * return value: success at successfull memory allocation for 
 * 	the array. Fail otherwise.
 *
*/

int	init_data(int argc, t_data *data)
{
	if (argc == 0 || !data)
		return (FAIL);
	data->array = NULL;
	data->size = 0;
	data->a.head = NULL;
	data->a.tail = NULL;
	data->b.head = NULL;
	data->b.tail = NULL;
	data->a.name = 'a';
	data->b.name = 'b';
	data->a.size = 0;
	data->b.size = 0;
	data->a.index_max = -1;
	data->b.index_min = -1;
	return (SUCCESS);
}

int	sort_and_check_unicity(int *array, size_t size)
{
	size_t	i;
	t_bool	sorted;
	int		tmp;

	sorted = FALSE;
	while (!sorted)
	{
		i = 0;
		sorted = TRUE;
		while (i < size - 1)
		{
			if (array[i] == array[i + 1])
				return (FAIL);
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				sorted = FALSE;
			}
			i++;
		}
	}
	return (SUCCESS);
}

void	fill_indexes_and_size(t_stack *s, int *array, size_t size)
{
	t_node	*cursor;

	cursor = s->head;
	while (cursor)
	{
		cursor->index = get_index(cursor->value, array, size);
		cursor = cursor->next;
	}
	s->size = size;
}

int	get_index(int value, int *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
