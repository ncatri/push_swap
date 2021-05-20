SRCS	= setup_stacks.c \
		  doubly_linked_list.c \
		  operations.c

OBJS 	= $(SRCS:.c=.o)

NAME	= push_swap
LIBFT	= libft
INC		= includes

RM 		= rm -f
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g -I. -I$(LIBFT)/includes -fsanitize=address

all: $(NAME)

$(NAME): $(LIBFT).a $(OBJS) main.c
	$(CC) $(CFLAGS) -L. -lft $(OBJS) main.c -o $(NAME)

$(LIBFT).a:
	$(MAKE) -C $(LIBFT)
	mv $(LIBFT)/$(LIBFT).a .

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)
	$(RM) $(LIBFT).a
	$(RM) -r $(NAME).dSYM

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)
