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
	if (!stacks->A || !stacks->B)
		return (FAIL);
	return (SUCCESS);
}

t_bool	is_valid_entry(int entry, char *str)
{
	int		num_len;
	t_bool	neg;

	neg = FALSE;
	if (*str == '-')
	{
		neg = TRUE;
		str++;
	}
	while (*str == '0')
		str++;
	num_len = ft_strlen(str);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	if (num_len > INTMAX_LEN)
		return (FALSE);
	else if (num_len == INTMAX_LEN && \
			((neg && entry > -2147483648) || (!neg && entry < 2147483647)))
		return (FALSE);
	else
		return (TRUE);
}

t_bool	is_unique(int entry)
{
	(void)entry;
	return (TRUE);
}
