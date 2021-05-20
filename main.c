#include "push_swap.h"

int main(int argc, char **argv)
{
	t_data	data;

	if (setup_data(argc, argv, &data) == FAIL || \
			sort_and_check_unicity(data.array, data.size) == FAIL)
		return (free_and_quit(data, EXIT_FAILURE));
	print_array(data.array, data.size);
	print_stack(data.a);

	printf("\n");
//	print_rev_list(stacks.a_head);
//	swap(&stacks.a_head);
//	print_list(stacks.a_head);
	return (EXIT_SUCCESS);
}


int	free_and_quit(t_data data, int return_value)
{
	free(data.array);
	dll_lstfree(&data.a.head);
	dll_lstfree(&data.b.head);
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
