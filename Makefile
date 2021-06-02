SRCS	= parsing/setup_stacks.c \
		  parsing/parsing.c \
		  list/doubly_linked_list.c \
		  operations/operations.c \
		  algo/algo.c \
		  algo/algo2.c \
		  algo/sort_three.c \
		  algo/utils.c \
		  algo/debug.c \

SRCS_BONUS	= bonus/operations_double.c

OBJS 	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME	= push_swap
LIBFT	= libft
INC		= includes

NAME_BONUS = checker

RM 		= rm -f
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g -I$(INC) -I$(LIBFT)/includes

%.o: %.c $(INC)/$(NAME).h 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(LIBFT).a

$(NAME): $(LIBFT).a $(OBJS) main.c
	$(CC) $(CFLAGS) -L. -lft $(OBJS) main.c -o $(NAME)

$(LIBFT).a:
	$(MAKE) -C $(LIBFT)
	mv $(LIBFT)/$(LIBFT).a .

bonus: $(NAME) $(OBJS_BONUS) $(LIBFT).a $(INC)/$(NAME).h
	$(CC) $(CFLAGS) -L. -lft $(OBJS) $(OBJS_BONUS) bonus/checker.c -o $(NAME_BONUS)

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
