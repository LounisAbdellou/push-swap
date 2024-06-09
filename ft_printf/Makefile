NAME = ft_printf.a
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -I ../includes

SRCS = ft_printf.c ft_putunbr_fd.c ft_unbrlen.c ft_puthex_fd.c ft_hexlen.c \
	   ft_ptrlen.c ft_putptr.c ft_handlers.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@cp ../libft/libft.a .
	@mv libft.a ${NAME}
	${AR} ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re libft
