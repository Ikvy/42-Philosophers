# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmidon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 16:37:36 by mmidon            #+#    #+#              #
#    Updated: 2022/04/06 17:03:07 by mmidon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= ft_isascii.c    ft_split.c      ft_strlcpy.c    ft_strrchr.c \
ft_atoi.c ft_strmapi.c ft_memmove.c ft_memchr.c ft_memcmp.c  ft_calloc.c ft_isdigit.c    ft_memset.c     ft_strchr.c     ft_strlen.c     ft_strtrim.c \
ft_bzero.c      ft_isprint.c   ft_putchar_fd.c ft_strdup.c     ft_strlen.o     ft_substr.c \
ft_isalnum.c  ft_striteri.c  ft_itoa.c       ft_putendl_fd.c ft_strjoin.c    ft_strncmp.c    ft_tolower.c \
ft_isalpha.c  ft_putstr_fd.c  ft_memcpy.c     ft_putnbr_fd.c  ft_strlcat.c    ft_strnstr.c    ft_toupper.c \

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	=  ${SRCS:.c=.o}

BONUS_OBJS	= ${BONUS:.c=.o}

NAME	= libft.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I.

all:	${NAME}


bonus:	
	@make SRCS="${SRCS} ${BONUS_OBJS}"

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}

	ar rc ${NAME} ${OBJS}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY: all bonus clean fclean re
