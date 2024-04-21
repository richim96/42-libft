SRC
OBJS	= ${SRC:.c=.o}
HEAD
NAME	= libft
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g

%.o:	%.c
	%{CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:
	${NAME}
clean:
	rm -f ${OBJS}
fclean:
	rm -f ${NAME}
re:
	fclean all
