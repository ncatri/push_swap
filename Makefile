SRCS	= setup_stacks.c \
		  parsing.c \
		  doubly_linked_list.c \
		  operations.c \
		  algo.c \
		  algo2.c \
		  sort_three.c \
		  debug.c \
		  utils.c

SRCS_BONUS	= checker_functions.c \
			  operations_double.c

OBJS 	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME	= push_swap
LIBFT	= libft
INC		= includes

NAME_BONUS = checker

RM 		= rm -f
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g -I. -I$(LIBFT)/includes

all: $(NAME)

$(NAME): $(LIBFT).a $(OBJS) main.c
	$(CC) $(CFLAGS) -L. -lft $(OBJS) main.c -o $(NAME)

$(LIBFT).a:
	$(MAKE) -C $(LIBFT)
	mv $(LIBFT)/$(LIBFT).a .

bonus: $(OBJS) $(OBJS_BONUS) $(LIBFT).a
	$(CC) $(CFLAGS) -L. -lft $(OBJS) $(OBJS_BONUS) checker.c -o $(NAME_BONUS)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)
	$(RM) $(LIBFT).a
	$(RM) -r $(NAME).dSYM
	$(RM) $(OBJS_BONUS)
	$(RM) -r $(NAME_BONUS).dSYM

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
