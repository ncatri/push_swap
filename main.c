#include "push_swap.h"

int main(int argc, char **argv)
{
	t_data	data;

	if (get_valid_input(argc, argv, &data) == FAIL || \
			fill_array(&data) == FAIL || \
			sort_and_check_unicity(data.array, data.size) == FAIL)
		return (free_and_quit(data, EXIT_FAILURE));
	fill_indexes_and_size(&data.a, data.array, data.size);
	if (data.size == 0 || is_sorted(&data.a))
		return (free_and_quit(data, EXIT_SUCCESS));
	if (data.size == 3)
		sort_three(&data.a);
	else if (data.size == 5)
		sort_five(&data);
	else
		split_two(&data);

	printf("stack a:\n");
	print_stack(data.a, INDEX);
	printf("stack b:\n");
	print_stack(data.b, INDEX);

	if (is_sorted(&data.a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	
	return (free_and_quit(data, EXIT_SUCCESS));
}

/*
int main(int argc, char **argv)
{
	int num;

	if (argc != 2)
		return (1);
	num = ft_atoi(argv[1]);
	printf("num: %d --> div: %d\n", num, get_division(num));
	return (0);
}
*/
