#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define ERROR "Error\n"

typedef	struct	s_stacks
{
	int		*A;
	size_t	a_size;

	int		*B;
	size_t	b_size;
}				t_stacks;

int	process_stacks(int argc, char **argv, t_stacks *stacks);
int	error_message(char *msg, int return_value);

# endif
