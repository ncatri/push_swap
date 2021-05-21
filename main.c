#include "push_swap.h"

int main(int argc, char **argv)
{
	t_data	data;

	if (get_valid_input(argc, argv, &data) == FAIL || \
			sort_and_check_unicity(data.array, data.size) == FAIL)
		return (free_and_quit(data, EXIT_FAILURE));
	fill_indexes(data.a, data.array, data.size);

/*	print_stack(data.a, INDEX);
	swap(&data.a);
	printf("after swap:\n");
	print_stack(data.a, INDEX);
	printf("reverse stack:\n");
	print_rev_stack(data.a, INDEX);
*/
	(&bubble_sort)(&data);	

	return (free_and_quit(data, EXIT_SUCCESS));
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
