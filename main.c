#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stacks	stacks;

	if (setup_stacks(argc, argv, &stacks) == FAIL)
		return (free_and_quit(stacks, EXIT_FAILURE));
	dll_print_list(stacks.a_head);
	return (EXIT_SUCCESS);
}


int	free_and_quit(t_stacks stacks, int return_value)
{
	free(stacks.A);
	free(stacks.B);
	if (return_value == EXIT_FAILURE)
		ft_putstr_fd(ERR_MSG, 2);
	return (return_value);
}
