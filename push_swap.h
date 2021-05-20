#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define ERR_MSG "Error\n"
# define FAIL	(0)
# define SUCCESS (1)

# define INTMAX_LEN (10)

typedef struct	s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	t_node *head;
	t_node *tail;
}				t_stack;

typedef	struct	s_data
{
	int		*array;
	size_t	size;

	t_stack	a;
	t_stack b;
}				t_data;

int	setup_data(int argc, char **argv, t_data *data);
int	free_and_quit(t_data data, int return_value);
int	init_data(int argc, t_data *data);
t_bool	is_invalid_entry(long entry, char *str);
int		sort_and_check_unicity(int *array, size_t size);

/*
 * singly linked list
 *
*/

t_node	*dll_create_node(int val);
void	dll_add_back(t_stack *stack, t_node *new);
void	dll_add_front(t_node **head, t_node *new);
void	dll_lstfree(t_node **head);
void	print_stack(t_stack s);
void	print_rev_stack(t_stack s);

void	print_array(int *array, size_t size);

/*
 * operations
 *
*/

void	swap(t_stack *s);
t_node	*get_tail(t_node *head);
void	rotate_stack(t_stack *s);

# endif
