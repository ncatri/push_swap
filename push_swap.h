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

enum e_datatype {VALUE, INDEX};
enum e_from {TOP, BOTTOM};

typedef struct	s_node
{
	int				value;
	int				index;

	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	char	name;
	t_node	*head;
	t_node	*tail;
	int		size;
}				t_stack;

typedef	struct	s_data
{
	int		*array;
	size_t	size;

	t_stack	a;
	t_stack b;
}				t_data;

typedef void	(*t_algo)(t_data *data);

int		get_valid_input(int argc, char **argv, t_data *data);
int		free_and_quit(t_data data, int return_value);
int		init_data(int argc, t_data *data);
t_bool	is_invalid_entry(long entry, char *str);
int		sort_and_check_unicity(int *array, size_t size);
void	fill_indexes_and_size(t_stack *s, int *array, size_t size);
int		get_index(int value, int *array, size_t size);
int		fill_array(t_data *data);
int		fill_stack(char *str, t_stack *s, size_t *size);

/*
 * singly linked list
 *
*/

t_node	*dll_create_node(int val);
void	dll_add_back(t_stack *stack, t_node *new);
void	dll_add_front(t_node **head, t_node *new);
void	dll_lstfree(t_node **head);
void	print_stack(t_stack s, int data);
void	print_rev_stack(t_stack s, int data);

void	print_array(int *array, size_t size);

/*
 * operations
 *
*/

void	swap(t_stack *s);
t_node	*get_tail(t_node *head);
void	rotate_stack(t_stack *s);
void	reverse_rotate_stack(t_stack *s);
void	push(t_stack *dst, t_stack *src);
void	print_operation(char *op, char stack_name);

/*
 * algo
 *
*/

void	bubble_sort(t_data *data);
t_bool	ordered(t_stack s);
void	sort_three(t_stack *stack);

void	split_two(t_data *data);
void	move_lower_values(int range, t_stack *dst, t_stack *src);
int		get_position_from(int range, t_stack *s, int from);
int		get_max_position(t_stack *s);
void	move_highest(t_stack *dst, t_stack *src);

# endif
