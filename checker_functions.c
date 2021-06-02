#include "push_swap.h"

t_bool	is_valid_instruction(char *line)
{
	if (ft_strcmp(line, "pa") == 0 || \
			ft_strcmp(line, "pb") == 0 || \
			ft_strcmp(line, "ra") == 0 || \
			ft_strcmp(line, "rb") == 0 || \
			ft_strcmp(line, "rra") == 0 || \
			ft_strcmp(line, "rrb") == 0 || \
			ft_strcmp(line, "sa") == 0 || \
			ft_strcmp(line, "sb") == 0 || \
			ft_strcmp(line, "ss") == 0 || \
			ft_strcmp(line, "rr")  == 0|| \
			ft_strcmp(line, "rrr")  == 0)
		return (TRUE);
	else
		return (FALSE);
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
