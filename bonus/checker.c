#include "push_swap.h"
#include <fcntl.h>

int	main(int argc, char **argv)
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
	while (get_next_line(0, &line))
	{
		if (execute_instruction(&data, line) == FAIL)
		{
			free(line);
			return (free_and_quit(data, EXIT_FAILURE));
		}
		free(line);
	}
	free(line);
	if (is_sorted(&data.a) && data.b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_and_quit(data, EXIT_SUCCESS));
}

int	execute_instruction(t_data *data, char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		push(&data->a, &data->b, QUIET);
	else if (ft_strcmp(line, "pb") == 0)
		push(&data->b, &data->a, QUIET);
	else if (ft_strcmp(line, "ra") == 0)
		rotate_stack(&data->a, QUIET);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_stack(&data->b, QUIET);
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate_stack(&data->a, QUIET);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate_stack(&data->b, QUIET);
	else if (ft_strcmp(line, "sa") == 0)
		swap(&data->a, QUIET);
	else if (ft_strcmp(line, "sb") == 0)
		swap(&data->b, QUIET);
	else if (ft_strcmp(line, "ss") == 0)
		swap_both(data);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_both(data);
	else if (ft_strcmp(line, "rrr") == 0)
		reverse_rotate_both(data);
	else
		return (FAIL);
	return (SUCCESS);
}
