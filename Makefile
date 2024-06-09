NAME = push_swap
INCLUDES = ./includes/
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft
	${CC} $(CFLAGS) -I $(INCLUDES) $(SRCS) -o $(NAME) $(LIBFT)

clean:
	@make clean -C libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
