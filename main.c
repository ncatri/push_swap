#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stacks	stacks;

	if (!process_stacks(argc, argv, &stacks))
		return (error_message(ERROR, 1));
	return (0);
}


int	process_stacks(int argc, char **argv, t_stacks *stacks)
{
//	int		i;
	(void)argv;
	if (argc == 1)
		return (0);
/*	i = 0;
	while (++i < argc)
	{
		entry = argv[i];

		if (!str_is_integer(entry) || !is_unique(entry))
			return (0);
	}
*/
	stacks->A = NULL;
	return (1);
}

int	error_message(char *msg, int return_value)
{
	ft_putstr_fd(msg, 2);
	return (return_value);
}
