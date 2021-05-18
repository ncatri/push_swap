#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define ERR_MSG "Error\n"
# define FAIL	(0)
# define SUCCESS (1)

# define INTMAX_LEN (10)

typedef	struct	s_stacks
{
	int		*A;
	size_t	a_size;

	int		*B;
	size_t	b_size;
}				t_stacks;

int	setup_stacks(int argc, char **argv, t_stacks *stacks);
int	free_and_quit(t_stacks stacks, int return_value);
int	init_stacks(int argc, t_stacks *stacks);
t_bool	is_valid_entry(int entry, char *str);
t_bool	is_unique(int entry);

# endif
