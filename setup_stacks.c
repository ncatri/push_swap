#include "push_swap.h"

/*
 * inputs:	- argument count
 * 			- argument vector
 * 			- pointer to stacks
 * return value: fail if any error in argument list. Success otherwise.
 *
*/

int	get_valid_input(int argc, char **argv, t_data *data)
{
	int		i;

	if (argc == 1 || init_data(argc, data) == FAIL)
		return (FAIL);
	i = 0;
	while (++i < argc)
	{
		if (fill_stack(argv[i], &data->a, &data->size) == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}

int	fill_stack(char *str, t_stack *s, size_t *size)
{
	char	**split;
	int		i;
	long	entry;
	t_node	*new;

	split = ft_split(str, " ");
	if (!split)
		return (FAIL);
	i = -1;
	while (split[++i])
	{
		entry = ft_atol(split[i]);
		new = dll_create_node(entry);
		if (is_invalid_entry(entry, split[i]) || !new)
		{
			free_split(split);
			return (FAIL);
		}
		(*size)++;
		dll_add_back(s, dll_create_node(entry));
	}
	free_split(split);
	return (SUCCESS);
}	

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
	data->size = 0;
	data->a.head = NULL;
	data->a.tail = NULL;
	data->b.head = NULL;
	data->b.tail = NULL;
	data->a.name = 'a';
	data->b.name = 'b';
	data->a.size = 0;
	data->b.size = 0;
	return (SUCCESS);
}

/*
 * inputs:	- value is taken as a long to easily check overflow
 * 			- string representation of the number
 * return value:   00000000000042 , -000000000000042 are valid
 * 				   00000-42 , 12b3 are invalid
 *
*/

t_bool	is_invalid_entry(long entry, char *str)
{
	size_t	num_len;
	t_bool	neg;
	char	*tmp;

	if (!str)
		return (FALSE);
	neg = FALSE;
	if (*str == '-')
	{
		neg = TRUE;
		str++;
	}
	while (*str == '0')
		str++;
	num_len = ft_strlen(str);
	tmp = str;
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			return (TRUE);
		tmp++;
	}
	if (num_len > INTMAX_LEN || entry < -2147483648 || entry > 2147483647)
		return (TRUE);
	return (FALSE);
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
