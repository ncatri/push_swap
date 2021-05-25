#include "push_swap.h"

int main(int argc, char **argv)
{
	t_data	data;

	if (get_valid_input(argc, argv, &data) == FAIL || \
			sort_and_check_unicity(data.array, data.size) == FAIL)
		return (free_and_quit(data, EXIT_FAILURE));
	fill_indexes_and_size(&data.a, data.array, data.size);
//	if (data.size == 3)
//		sort_three(&data.a);
	
/*	printf("stack a:\n");
	print_stack(data.a, INDEX);
	printf("stack b:\n");
	print_stack(data.b, INDEX);
*/
	split_two(&data);

/*	printf("stack a:\n");
	print_stack(data.a, INDEX);
	printf("stack b:\n");
	print_stack(data.b, INDEX);
*/	
	return (free_and_quit(data, EXIT_SUCCESS));
}
