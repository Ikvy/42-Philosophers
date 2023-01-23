SRCS = main.c srcs/error.c srcs/ft_atoi.c srcs/ft_calloc.c srcs/ft_bzero.c srcs/ft_memset.c srcs/thread.c srcs/utils.c srcs/utils_2.c

OBJS	=  ${SRCS:.c=.o}

NAME	= philo
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

${NAME}:	${OBJS}
	@echo "Cooking spaghettis"
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
