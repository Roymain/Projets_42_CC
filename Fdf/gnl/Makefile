# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 02:39:01 by rcuminal          #+#    #+#              #
#    Updated: 2021/11/24 04:29:19 by rcuminal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

SRCS = get_next_line.c \

 
OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

FLAGS = -Wall -Werror -Wextra

%.o : %.c get_next_line.h
	${CC} ${FLAGS} -I includes -c $< -o $@

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS} 

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re
	