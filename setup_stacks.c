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
	long	entry;

	if (argc == 1 || init_data(argc, data) == FAIL)
		return (FAIL);
	i = 0;
	while (++i < argc)
	{
		entry = ft_atol(argv[i]);
		if (is_invalid_entry(entry, argv[i]))
			return (FAIL);
		data->array[i - 1] = entry;
		dll_add_back(&data->a, dll_create_node(entry));
	}
//	print_array(stacks->array, stacks->size);
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
	size_t	size;

	if (argc == 0 || !data)
		return (FALSE);
	size = argc - 1;
	data->size = size;
	data->array = malloc(sizeof(int) * size);
	data->a.head = NULL;
	data->a.tail = NULL;
	data->b.head = NULL;
	data->b.tail = NULL;
	if (!data->array)
		return (FAIL);
	data->a.name = 'a';
	data->b.name = 'b';
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

void	fill_indexes(t_stack s, int *array, size_t size)
{
	t_node	*cursor;

	cursor = s.head;
	while (cursor)
	{
		cursor->index = get_index(cursor->value, array, size);
		cursor = cursor->next;
	}
}

int	get_index(int value, int *array, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
