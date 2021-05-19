#include "push_swap.h"

/*
 * inputs:	- argument count
 * 			- argument vector
 * 			- pointer to stacks
 * return value: fail if any error in argument list. Success otherwise.
 *
*/

int	setup_stacks(int argc, char **argv, t_stacks *stacks)
{
	int		i;
	int		entry;

	if (argc == 1 || init_stacks(argc, stacks) == FAIL)
		return (FAIL);
	i = 0;
	while (++i < argc)
	{
		entry = ft_atoi(argv[i]);
		if (!is_valid_entry(entry, argv[i]) || !is_unique(entry))
			return (FAIL);
		dll_add_back(&stacks->a_head, dll_create_node(entry));
	}
	return (SUCCESS);
}

/*
 * inputs:	- argument count from main
 * 			- pointer to stacks
 * return value: success at successfull memory allocation for 
 * 	the 2 stacks. Fail otherwise.
 *
*/

int	init_stacks(int argc, t_stacks *stacks)
{
	size_t	size;

	if (argc == 0 || !stacks)
		return (FALSE);
	size = argc - 1;
	stacks->a_size = size;
	stacks->b_size = size;
	stacks->A = malloc(sizeof(int) * size);
	stacks->B = malloc(sizeof(int) * size);
	stacks->a_head = NULL;
	if (!stacks->A || !stacks->B)
		return (FAIL);
	return (SUCCESS);
}

t_bool	is_valid_entry(int entry, char *str)
{
	int		num_len;
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
			return (FALSE);
		tmp++;
	}
	if (num_len > INTMAX_LEN || \
			(num_len == INTMAX_LEN && is_different(str, entry)))
		return (FALSE);
	return (TRUE);
}

t_bool	is_different(char *str, int entry)
{
	char *entry_str;

	entry_str = ft_itoa(entry);
	printf("ft_itoa: |%s|\n", entry_str);
	entry_str++;
	return (ft_strcmp(str, entry_str));
}

t_bool	is_unique(int entry)
{
	(void)entry;
	return (TRUE);
}
