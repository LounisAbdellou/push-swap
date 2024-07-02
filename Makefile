NAME = push_swap
INCLUDES = ./includes/
CFLAGS = -Wall -Wextra -Werror -I ./includes
LIBFT = ./libft/libft.a

SRCS = push_swap.c stack_utils.c stack_utils2.c push.c swap.c rotate.c \
			 sort_utils.c nodes_utils.c nodes_utils2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	${CC} $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

clean:
	@make clean -C libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
