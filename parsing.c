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

	if (init_data(argc, data) == FAIL)
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
			free(new);
			return (FAIL);
		}
		(*size)++;
		dll_add_back(s, new);
	}
	free_split(split);
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
