#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stacks	stacks;

	if (setup_stacks(argc, argv, &stacks) == FAIL || \
			sort_and_check_unicity(stacks.array, stacks.size) == FAIL)
		return (free_and_quit(stacks, EXIT_FAILURE));
	print_array(stacks.array, stacks.size);
	dll_print_list(stacks.a_head);
	return (EXIT_SUCCESS);
}


int	free_and_quit(t_stacks stacks, int return_value)
{
	free(stacks.array);
	dll_lstfree(&stacks.a_head);
	dll_lstfree(&stacks.b_head);
	if (return_value == EXIT_FAILURE)
		ft_putstr_fd(ERR_MSG, 2);
	return (return_value);
}

void	print_array(int *array, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		printf(" %d :", array[i]);
		i++;
	}
	printf("\n");
}
