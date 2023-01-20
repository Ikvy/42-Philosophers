SRCS = main.c srcs/error.c srcs/thread.c srcs/utils.c

LIBFT   = libft/libft.a

OBJS	=  ${SRCS:.c=.o}

NAME	= philo
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

all:	LIBFT_M ${NAME}

LIBFT_M :
	@make -s -C libft/ all

${NAME}:	${OBJS}
	@echo "Cooking spaghettis"
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

clean:
		${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
