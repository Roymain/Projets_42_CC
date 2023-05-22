# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 22:26:37 by rcuminal          #+#    #+#              #
#    Updated: 2021/12/14 03:29:23 by rcuminal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBS_PERSO = libft/libft.a \
			gnl/gnl.a \


SRCS =  fdf.c       \
		parsing.c	\
		draw.c		\
		
		
OBJS = ${SRCS:.c=.o}

VERIF = -g3 -fsanitize=address

CC = gcc

RM = rm -f
	
%.o: %.c fdf.h
	$(CC) -Imlx -c $< -o $@
	
$(NAME): $(OBJS)
	make -C libmlx
	make -C libft
	make -C gnl
	$(CC) -Llibmlx -lmlx -framework OpenGL -framework AppKit $(VERIF) $(LIBS_PERSO) $(OBJS) -o $(NAME)
	
all: ${NAME}

clean:
	${RM} ${OBJS}
	make -C libmlx clean
	make -C libft fclean
	make -C gnl fclean
	
fclean: clean
	${RM} ${NAME}
	
re: fclean all

.PHONY: all clean fclean re