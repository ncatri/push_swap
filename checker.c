#include "push_swap.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	t_data	data;
	char	*line;

	if (get_valid_input(argc, argv, &data) == FAIL || \
			fill_array(&data) == FAIL || \
			sort_and_check_unicity(data.array, data.size) == FAIL)
		return (free_and_quit(data, EXIT_FAILURE));
	fill_indexes_and_size(&data.a, data.array, data.size);
	if (data.size == 0)
		return (free_and_quit(data, EXIT_SUCCESS));

//	int fd = open("ope.ps", O_RDONLY);
	while (get_next_line(0, &line))
	{
		if (execute_instruction(&data, line) == FAIL)
		{
			free(line);
			return (free_and_quit(data, EXIT_FAILURE));
		}
		free(line);
//		print_stack(data.a, VALUE);
//		print_stack(data.b, VALUE);
	}
	free(line);
	if (is_sorted(&data.a) && data.b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_and_quit(data, EXIT_SUCCESS));
}

