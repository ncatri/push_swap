#include "push_swap.h"

int	main(int argc, char **argv)
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
	return (free_and_quit(data, EXIT_SUCCESS));
}
