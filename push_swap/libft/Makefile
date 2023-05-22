# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 19:44:56 by rcuminal          #+#    #+#              #
#    Updated: 2022/01/03 19:54:17 by rcuminal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCEND 		=   	\033[0m
CCYAN 		=   	\033[34m
CGREEN		=   	\033[33m
CCRED 		=   	\033[31m
CCPURPLE 	=   	\033[35m

EXEC 		= 	 libft
NAME 		= 	 $(EXEC).a
CC 			= 	 gcc

PATH_SRC	=	./srcs/
PATH_OBJ	=	./objs/

SRC		= ft_atoi.c \
	   ft_calloc.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_memchr.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strchr.c \
	   ft_strlcat.c \
	   ft_strlen.c \
	   ft_strnstr.c \
	   ft_bzero.c \
	   ft_isalnum.c \
	   ft_strrchr.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_memcmp.c \
	   ft_memset.c \
	   ft_strdup.c \
	   ft_strncmp.c \
	   ft_itoa.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strmapi.c \
	   ft_strtrim.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_strlcpy.c \
	   ft_split.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJ_SRC		=	$(SRC:.c=.o)

SRC_O		=	$(addprefix $(PATH_SRC), $(SRC))
OBJ_S		=	$(addprefix $(PATH_OBJ), $(OBJ_SRC))

HEADER 		= 	includes/$(EXEC).h
MK			= 	Makefile
FLAGS 		= 	-Wall -Werror -Wextra -ggdb 



$(PATH_OBJ)%.o : $(PATH_SRC)%.c $(HEADER) $(MK)
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	@-$(CC) $(FLAGS) -I ./includes -o $@ -c $<
	@printf "\r\t\033[K$(CCYAN)\t$< $(CCPURPLE)--> $(CCYAN)$@ $(CCEND)"
	@sleep 0.1

all: $(NAME)

$(NAME): $(OBJ_S)
	@printf "\r\t\033[K$(CCYAN)[✅]\t$(EXEC) $(CCPURPLE)--> $(CCYAN) Gen Objs$(CCEND)"
	@printf "\n$(CCYAN)[✅]\t$(CCPURPLE)Creation of Objs $(EXEC)...$(CCEND)\n"
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(PATH_OBJ)$(NAME) $(OBJ_S)

clean:
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(EXEC) Object...$(CCEND)\n"
	@-/bin/rm -rf $(PATH_OBJ)*.o

fclean: clean
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	@-/bin/rm -f $(PATH_OBJ)*.a
	@-/bin/rm -rf $(PATH_OBJ)
	@-/bin/rm -f Tags
	@-/bin/rm -f $(EXEC)

.PHONY: all clean fclean re
.SILENT :
re: fclean all
