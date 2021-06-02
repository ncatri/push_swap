#include "push_swap.h"

void	rotate_both(t_data *data)
{
	rotate_stack(&data->a, QUIET);
	rotate_stack(&data->b, QUIET);
}

void	reverse_rotate_both(t_data *data)
{
	reverse_rotate_stack(&data->a, QUIET);
	reverse_rotate_stack(&data->b, QUIET);
}

void	swap_both(t_data *data)
{
	swap(&data->a, QUIET);
	swap(&data->b, QUIET);
}
